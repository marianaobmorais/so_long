/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_rabbits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:54:41 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/07 15:58:01 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

static int	*count_rabbits(char **matrix, int *count)
{
	int		i;
	int		j;

	*count = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'R')
				(*count)++;
			j++;
		}
		i++;
	}
	return (count);
}

t_point	*find_rabbits(char **matrix, int *count)
{
	t_point	*rabbits;
	t_point	pos;
	int		i;
	int		j;
	
	count = count_rabbits(matrix, count);
	rabbits = (t_point *)malloc(sizeof(t_point) * (*count));
	if (!rabbits)
		return (NULL);
	*count = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'R')
			{
				pos.x = i;
				pos.y = j;
				rabbits[(*count)++] = pos;
			}
			j++;
		}
		i++;
	}
	return (rabbits);
}

void move_rabbits(t_game *game)
{
	t_point	*rabbits;
	int		count;
	int		i;
	int		dir;
	int		game_over;

	rabbits = find_rabbits(game->map->matrix, &count);
	if (!rabbits)
		return;
	i = 0;
	game_over = 0;
	while (i < count)
	{
		dir = rand() % 4;
		if (dir == 0)
			game_over = rabbit_left(game, rabbits[i]);
		else if (dir == 1)
			game_over = rabbit_right(game, rabbits[i]);
		else if (dir == 2)
			game_over = rabbit_up(game, rabbits[i]);
		else if (dir == 3)
			game_over = rabbit_down(game, rabbits[i]);
		if (game_over)
		{
			free(rabbits);
			close_window(game);
		}
		i++;
	}
	free(rabbits);
}
