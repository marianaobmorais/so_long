/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:37:14 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/02 17:50:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x + 1][pos.y] == '1')
		return ;
	if (matrix[pos.x + 1][pos.y] == 'E')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		if (game->map->c_count == 0)
		{
			game->move_count += 1;
			game->map->p_position.x -= 1;
			ft_printf("Move count: %i\n", game->move_count);
			ft_printf(GAME_COMPLETE);
			close_window(game);
		}
	}
	if (matrix[pos.x + 1][pos.y] == 'C')
	{
		matrix[pos.x + 1][pos.y] = '0';
		game->map->c_count -= 1;
		if (matrix[pos.x][pos.y] == 'E')
		{
			put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		}
		else
		{
			put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		}
	}
	else
	{
		if (matrix[pos.x][pos.y] == 'E')
		{
			put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		}
		else
		{
			put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
			put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		}
	}
	game->move_count += 1;
	game->map->p_position.x += 1;
	ft_printf("Move count: %i\n", game->move_count);
}

/* void	move_down(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x + 1][pos.y] == '1')
		return ;
	if (matrix[pos.x + 1][pos.y] == 'E' && game->map->c_count == 0)
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		game->move_count += 1;
		game->map->p_position.y += 1;
		ft_printf("Move count: %i\n", game->move_count);
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
	if (matrix[pos.x + 1][pos.y] == 'E')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
	}
	if (matrix[pos.x + 1][pos.y] == 'C' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		matrix[pos.x + 1][pos.y] = '0';
		game->map->c_count -= 1;
	}
	else if (matrix[pos.x + 1][pos.y] == 'C')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
		matrix[pos.x + 1][pos.y] = '0';
		game->map->c_count -= 1;
	}
	if (matrix[pos.x + 1][pos.y] == '0' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
	}
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x += 1;
	ft_printf("Move count: %i\n", game->move_count);
} */