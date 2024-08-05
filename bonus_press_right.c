/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_press_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:41:42 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/05 21:28:22 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void	move_right(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == 'C')
	{
		matrix[pos.x][pos.y + 1] = '0';
		game->map->c_count -= 1;
	}
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/b_e1.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_r.xpm", (pos.y + 1) * PIXEL,
			pos.x * PIXEL);
	}
/* 	if (matrix[pos.x][pos.y] == 'R')//
	{
		put_tile(game, "./textures/r_f.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_r.xpm", (pos.y + 1) * PIXEL,
			pos.x * PIXEL);
	} */
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_r.xpm", (pos.y + 1) * PIXEL,
			pos.x * PIXEL);
	}
}

void	press_right(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == '1')
	{
		put_tile(game, "./textures/p_r.xpm", pos.y * PIXEL, pos.x * PIXEL);
		return ;
	}
	else
		move_right(game);
	game->move_count += 1;
	game->map->p_position.y += 1;
 	if (matrix[pos.x][pos.y + 1] == 'R')
	{
		ft_printf(GAME_LOST);
		close_window(game);
	}
	if (matrix[pos.x][pos.y + 1] == 'E' && game->map->c_count == 0)
	{
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
}
