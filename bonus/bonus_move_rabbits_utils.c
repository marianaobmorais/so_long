/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_rabbits_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:34:55 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 14:40:36 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

int	rabbit_left(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y - 1] == '1' || matrix[pos.x][pos.y - 1] == 'R')
		return (0);
	if (matrix[pos.x][pos.y - 1] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	if (matrix[pos.x][pos.y - 1] == 'P')
		return (ft_printf(GAME_LOST), 1);
	if (matrix[pos.x][pos.y - 1] == 'E')
		return (ft_printf(GAME_LOST_E), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_l.xpm", (pos.y - 1) * PIXEL,
		pos.x * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x][pos.y - 1] = 'R';
	return (0);
}

int	rabbit_right(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x][pos.y + 1] == '1' || matrix[pos.x][pos.y + 1] == 'R')
		return (0);
	if (matrix[pos.x][pos.y + 1] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	if (matrix[pos.x][pos.y + 1] == 'P')
		return (ft_printf(GAME_LOST), 1);
	if (matrix[pos.x][pos.y + 1] == 'E')
		return (ft_printf(GAME_LOST_E), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_r.xpm", (pos.y + 1) * PIXEL,
		pos.x * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x][pos.y + 1] = 'R';
	return (0);
}

int	rabbit_down(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x + 1][pos.y] == '1' || matrix[pos.x + 1][pos.y] == 'R')
		return (0);
	if (matrix[pos.x + 1][pos.y] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	if (matrix[pos.x + 1][pos.y] == 'P')
		return (ft_printf(GAME_LOST), 1);
	if (matrix[pos.x + 1][pos.y] == 'E')
		return (ft_printf(GAME_LOST_E), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_f.xpm", pos.y * PIXEL,
		(pos.x + 1) * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x + 1][pos.y] = 'R';
	return (0);
}

int	rabbit_up(t_game *game, t_point pos)
{
	char	**matrix;

	matrix = game->map->matrix;
	if (matrix[pos.x - 1][pos.y] == '1' || matrix[pos.x - 1][pos.y] == 'R')
		return (0);
	if (matrix[pos.x - 1][pos.y] == 'C')
		return (ft_printf(GAME_LOST_C), 1);
	if (matrix[pos.x - 1][pos.y] == 'E')
		return (ft_printf(GAME_LOST_E), 1);
	if (matrix[pos.x - 1][pos.y] == 'P')
		return (ft_printf(GAME_LOST), 1);
	put_tile(game, "./textures/0.xpm", pos.y * PIXEL, pos.x * PIXEL);
	put_tile(game, "./textures/r_b.xpm", pos.y * PIXEL,
		(pos.x - 1) * PIXEL);
	matrix[pos.x][pos.y] = '0';
	matrix[pos.x - 1][pos.y] = 'R';
	return (0);
}
