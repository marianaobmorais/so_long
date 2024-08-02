/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:36:38 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/02 18:18:26 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y - 1] == '1')
		return ;
	if (matrix[pos.x][pos.y - 1] == 'E')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		if (game->map->c_count == 0)
		{
			game->move_count += 1;
			game->map->p_position.y += 1;
			ft_printf("Move count: %i\n", game->move_count);
			ft_printf(GAME_COMPLETE);
			close_window(game);
		}
	}
/* 	if (matrix[pos.x][pos.y - 1] == 'C')
	{
		matrix[pos.x][pos.y - 1] = '0';
		game->map->c_count -= 1;
		if (matrix[pos.x][pos.y] == 'E')    /// esse
		{
			put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		}
		else
		{
			put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		}
	} */
	else
	{
		if (matrix[pos.x][pos.y - 1] == 'C')
		{
			matrix[pos.x][pos.y - 1] = '0';
			game->map->c_count -= 1;
		}
		if (matrix[pos.x][pos.y] == 'E')    /// igual a esse
		{
			put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		}
		else
		{
			put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		}
	}
	game->move_count += 1;
	game->map->p_position.y -= 1;
	ft_printf("Move count: %i\n", game->move_count);
}
