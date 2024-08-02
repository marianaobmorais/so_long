/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:41:42 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/02 16:20:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_up(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] == '1')
		return ;
	if (matrix[pos.x - 1][pos.y] == 'E' && game->map->c_count == 0)
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
	if (matrix[pos.x - 1][pos.y] == 'E')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
	}
	if (matrix[pos.x - 1][pos.y] == 'C' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		matrix[pos.x - 1][pos.y] = '0';
		game->map->c_count -= 1;
	}
	else if (matrix[pos.x - 1][pos.y] == 'C')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
		matrix[pos.x - 1][pos.y] = '0';
		game->map->c_count -= 1;
	}
	if (matrix[pos.x - 1][pos.y] == '0' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
	}
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", pos.y * PIXEL, (pos.x - 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x -= 1;
	ft_printf("Move count: %i\n", game->move_count);
}

void	check_down(t_game *game)
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
}

void	check_left(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y - 1] == '1')
		return ;
	if (matrix[pos.x][pos.y - 1] == 'E' && game->map->c_count == 0)
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
	if (matrix[pos.x][pos.y - 1] == 'E')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
	}
	if (matrix[pos.x][pos.y - 1] == 'C' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		matrix[pos.x][pos.y - 1] = '0';
		game->map->c_count -= 1;
	}
	else if (matrix[pos.x][pos.y - 1] == 'C')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
		matrix[pos.x][pos.y - 1] = '0';
		game->map->c_count -= 1;
	}
	if (matrix[pos.x][pos.y - 1] == '0' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
	}
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y - 1) * PIXEL, pos.x * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.y -= 1;
	ft_printf("Move count: %i\n", game->move_count);
}

void	check_right(t_game *game)
{
	t_point	pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == '1')
		return ;
	if (matrix[pos.x][pos.y + 1] == 'E' && game->map->c_count == 0)
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		ft_printf(GAME_COMPLETE);
		close_window(game);
	}
	if (matrix[pos.x][pos.y + 1] == 'E')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
	}
	if (matrix[pos.x][pos.y + 1] == 'C' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		matrix[pos.x][pos.y + 1] = '0';
		game->map->c_count -= 1;
	}
	else if (matrix[pos.x][pos.y + 1] == 'C')
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
		matrix[pos.x][pos.y + 1] = '0';
		game->map->c_count -= 1;
	}
	if (matrix[pos.x][pos.y + 1] == '0' && matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./textures/e.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
	}
	else
	{
		put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./textures/p_f.xpm", (pos.y + 1) * PIXEL, pos.x * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.y += 1;
	ft_printf("Move count: %i\n", game->move_count);
}


