/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_knights.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:55:56 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 15:17:21 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

static void	validate_move_knights(t_game *game, t_point pos)
{
	int		dir;

	dir = rand() % 4;
	if (dir == 0)
		put_tile(game, "./textures/c.xpm", pos.y * PIXEL, pos.x * PIXEL);
	else if (dir == 1)
		put_tile(game, "./textures/c_b.xpm", pos.y * PIXEL, pos.x * PIXEL);
	else if (dir == 2)
		put_tile(game, "./textures/c_l.xpm", pos.y * PIXEL, pos.x * PIXEL);
	else if (dir == 3)
		put_tile(game, "./textures/c_r.xpm", pos.y * PIXEL, pos.x * PIXEL);
}

void	move_knights(t_game *game)
{
	t_point	*knights;
	int		count;
	int		i;

	knights = find_animated(game->map->matrix, &count, 'C');
	if (!knights)
		return ;
	i = 0;
	while (i < count)
	{
		validate_move_knights(game, knights[i]);
		i++;
	}
	free(knights);
}
