/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:49:33 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/01 15:44:22 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		check_left(game);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		check_right(game);
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		check_up(game);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		check_down(game);
	return (0);
}
