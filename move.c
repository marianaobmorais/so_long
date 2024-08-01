/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:45:42 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/01 16:50:46 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y) * PIXEL,
			(pos.x - 1) * PIXEL);
	}
	else
	{
		if (matrix[pos.x - 1][pos.y] == 'C')
		{
			matrix[pos.x - 1][pos.y] = '0';
			game->map->c_count -= 1;
		}
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y) * PIXEL,
			(pos.x - 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x -= 1;
	ft_printf("Move count: %i\n", game->move_count);
}

void	move_down(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL,
			(pos.x + 1) * PIXEL);
	}
	else
	{
		if (matrix[pos.x + 1][pos.y] == 'C')
		{
			matrix[pos.x + 1][pos.y] = '0';
			game->map->c_count -= 1;
		}
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL,
			(pos.x + 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x += 1;
	ft_printf("Move count: %i\n", game->move_count);
}

void	move_left(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL,
			pos.x * PIXEL);
	}
	else
	{
		if (matrix[pos.x][pos.y - 1] == 'C')
		{
			matrix[pos.x][pos.y - 1] = '0';
			game->map->c_count -= 1;
		}
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL,
			pos.x * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.y -= 1;
	ft_printf("Move count: %i\n", game->move_count);
}

void	move_right(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL,
			pos.x * PIXEL);
	}
	else
	{
		if (matrix[pos.x][pos.y + 1] == 'C')
		{
			matrix[pos.x][pos.y + 1] = '0';
			game->map->c_count -= 1;
		}
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL,
			pos.x * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.y += 1;
	ft_printf("Move count: %i\n", game->move_count);
}