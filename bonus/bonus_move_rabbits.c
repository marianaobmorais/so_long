/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_rabbits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:50:08 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 15:09:46 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

static int	validate_move_rabbits(t_game *game, t_point *rabbits, int count)
{
	int		i;
	int		dir;
	int		game_over;

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
			return (0);
		i++;
	}
	return (1);
}

void	move_rabbits(t_game *game)
{
	t_point	*rabbits;
	int		count;

	rabbits = find_animated(game->map->matrix, &count, 'R');
	if (!rabbits)
		return ;
	if (!validate_move_rabbits(game, rabbits, count))
	{
		free(rabbits);
		close_window(game);
	}
	free(rabbits);
}
