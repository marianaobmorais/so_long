/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hook_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:49:33 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 14:28:11 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

int	game_over(char **matrix, int x, int y, int c_count)
{
	if (matrix[x][y] == 'R')
	{
		ft_printf(GAME_LOST);
		return (1);
	}
	if (matrix[x][y] == 'E' && c_count == 0)
	{
		ft_printf(GAME_COMPLETE);
		return (1);
	}
	return (0);
}

int	close_window(t_game *game)
{
	free_structs(game);
	exit (0);
}

int	key_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_window(game);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		press_left(game);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		press_right(game);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		press_up(game);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		press_down(game);
	print_move(game);
	if (game->map->c_count == 0)
	{
		put_tile(game, "./textures/b_e2.xpm", game->map->e_position.y * PIXEL,
			game->map->e_position.x * PIXEL);
		put_tile(game, "./textures/b_e3.xpm", game->map->e_position.y * PIXEL,
			game->map->e_position.x * PIXEL);
	}
	return (0);
}
