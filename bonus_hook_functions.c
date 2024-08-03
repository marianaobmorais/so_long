/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hook_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:49:33 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/03 18:12:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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
	return (0);
}
