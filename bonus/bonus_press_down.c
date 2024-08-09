/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_press_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:37:14 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 14:33:48 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

static void	move_down(t_game *game, t_point pos, char **matrix)
{
	if (matrix[pos.x + 1][pos.y] == 'C')
	{
		matrix[pos.x + 1][pos.y] = '0';
		game->map->c_count -= 1;
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL,
			(pos.x + 1) * PIXEL);
	}
	else if (matrix[pos.x][pos.y] == 'R')
	{
		put_tile(game, "./textures/r_f.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL,
			(pos.x + 1) * PIXEL);
	}
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL,
			(pos.x + 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x += 1;
}

void	press_down(t_game *game)
{
	t_point	pos;
	t_point	e_pos;
	char	**matrix;

	pos = game->map->p_position;
	e_pos = game->map->e_position;
	matrix = game->map->matrix;
	if (matrix[pos.x + 1][pos.y] == '1')
	{
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, pos.x * PIXEL);
		return ;
	}
	else
		move_down(game, pos, matrix);
	if (game_over(matrix, pos.x + 1, pos.y, game->map->c_count))
		close_window(game);
	matrix[pos.x + 1][pos.y] = 'P';
	if (pos.x == e_pos.x && pos.y == e_pos.y)
	{
		matrix[pos.x][pos.y] = 'E';
		put_tile(game, "./textures/b_e1.xpm", pos.y * PIXEL, pos.x * PIXEL);
	}
	else
		matrix[pos.x][pos.y] = '0';
}
