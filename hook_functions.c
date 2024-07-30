/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:49:33 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/30 18:16:01 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_structs(game);
		exit (0);
	}
	if (keysym == XK_A || keysym == XK_D || keysym == XK_W || keysym == XK_S
		|| keysym == XK_a || keysym == XK_d || keysym == XK_w || keysym == XK_s)
	{
		game->move_count += 1;
		ft_printf("Movement count: %i\n", game->move_count);
	}
	if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
	{
		game->move_count += 1;
		ft_printf("Movement count: %i\n", game->move_count);
	}
	return (0);
}

int	close_window(t_game *game)
{
	free_structs(game);
	exit (0);
}
