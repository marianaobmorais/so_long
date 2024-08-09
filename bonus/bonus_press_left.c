/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_press_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:36:38 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 14:27:41 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

static void	move_left(t_game *game, t_point pos, char **matrix)
{
	if (matrix[pos.x][pos.y - 1] == 'C')
	{
		matrix[pos.x][pos.y - 1] = '0';
		game->map->c_count -= 1;
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_l.xpm", (pos.y - 1) * PIXEL,
			pos.x * PIXEL);
	}
	else if (matrix[pos.x][pos.y] == 'R')
	{
		put_tile(game, "./textures/r_f.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_l.xpm", (pos.y - 1) * PIXEL,
			pos.x * PIXEL);
	}
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_l.xpm", (pos.y - 1) * PIXEL,
			pos.x * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.y -= 1;
}

void	press_left(t_game *game)
{
	t_point	pos;
	t_point	e_pos;
	char	**matrix;

	pos = game->map->p_position;
	e_pos = game->map->e_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y - 1] == '1')
	{
		put_tile(game, "./textures/p_l.xpm", pos.y * PIXEL, pos.x * PIXEL);
		return ;
	}
	else
		move_left(game, pos, matrix);
	if (game_over(matrix, pos.x, pos.y - 1, game->map->c_count))
		close_window(game);
	matrix[pos.x][pos.y - 1] = 'P';
	if (pos.x == e_pos.x && pos.y == e_pos.y)
	{
		matrix[pos.x][pos.y] = 'E';
		put_tile(game, "./textures/b_e1.xpm", pos.y * PIXEL, pos.x * PIXEL);
	}
	else
		matrix[pos.x][pos.y] = '0';
}
