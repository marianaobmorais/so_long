/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_rabbit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:54:41 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/05 20:57:24 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

t_point	*find_rabbits(char **matrix, int *count)
{
	t_point	*rabbits;
	t_point	pos;
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

int rabbit_left(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y - 1] == '1' || matrix[pos.x][pos.y - 1] == 'R')
		return (0);
	if (matrix[pos.x][pos.y - 1] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_l.xpm", (pos.y - 1) * PIXEL,
		pos.x * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x][pos.y - 1] = 'R';
	pos.y -= 1;
	return (0);
}

int rabbit_right(t_game *game, t_point pos)
{
	char	**matrix;
	
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == '1' || matrix[pos.x][pos.y + 1] == 'R')
		return (0);
	if (matrix[pos.x][pos.y + 1] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_r.xpm", (pos.y + 1) * PIXEL,
		pos.x * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x][pos.y + 1] = 'R';
	pos.y += 1;
	return (0);
}

int rabbit_down(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x + 1][pos.y] == '1' || matrix[pos.x + 1][pos.y] == 'R')
		return (0);
	if (matrix[pos.x + 1][pos.y] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_f.xpm", pos.y * PIXEL,
		(pos.x + 1) * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x + 1][pos.y] = 'R';
	pos.x += 1;
	return (0);
}

int rabbit_up(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] == '1' || matrix[pos.x - 1][pos.y] == 'R')
		return (0);
	if (matrix[pos.x - 1][pos.y] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_b.xpm", pos.y * PIXEL,
		(pos.x - 1) * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x - 1][pos.y] = 'R';
	pos.x -= 1;
	return (0);
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
	for (i = 0; i < count; i++) {
		if (game->map->p_position.x == rabbits[i].x && game->map->p_position.y == rabbits[i].y)
		{
			free(rabbits);
			ft_printf(GAME_LOST);
			close_window(game);
		}
	}
	free(rabbits);
}
