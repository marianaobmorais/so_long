/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:49:33 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/31 19:29:57 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	t_point pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;

	if (matrix[pos.x - 1][pos.y] == '1')
	{
		ft_printf("it's a wall, stop\n");
		return ;
	}
	if (matrix[pos.x - 1][pos.y] == 'E' && game->map->c_count == 0)
	{
		ft_printf("game is complete\n");
		return ;
	}
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./img/exit.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./img/player/front.xpm", (pos.y) * PIXEL, (pos.x - 1) * PIXEL);
	}
/* 	if (matrix[pos.x - 1][pos.y] == 'C')
	{
		ft_printf("found C\n");
		put_tile(game, "./img/floor.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./img/player/front.xpm", (pos.y) * PIXEL, (pos.x - 1) * PIXEL);
		matrix[pos.x - 1][pos.y] = '0';
		game->map->c_count -= 1;
		ft_printf("C count: %i\n", game->map->c_count);
	} */
	else
	{
		if (matrix[pos.x - 1][pos.y] == 'C')
		{
			//ft_printf("found C\n");
			//put_tile(game, "./img/floor.xpm", pos.y * PIXEL, pos.x * PIXEL);
			//put_tile(game, "./img/player/front.xpm", (pos.y) * PIXEL, (pos.x - 1) * PIXEL);
			matrix[pos.x - 1][pos.y] = '0';
			game->map->c_count -= 1;
			//ft_printf("C count: %i\n", game->map->c_count);
		}
		
		put_tile(game, "./img/floor.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./img/player/front.xpm", (pos.y) * PIXEL, (pos.x - 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x -= 1;
	ft_printf("Movement count: %i\n", game->move_count);
}

void	move_down(t_game *game)
{
	t_point pos;
	char	**matrix;

	pos = game->map->p_position;
	matrix = game->map->matrix;

	if (matrix[pos.x + 1][pos.y] == '1')
	{
		ft_printf("it's a wall, stop\n");
		return ;
	}
	if (matrix[pos.x + 1][pos.y] == 'E' && game->map->c_count == 0)
	{
		ft_printf("game is complete\n");
		return ;
	}
	if (matrix[pos.x][pos.y] == 'E')
	{
		put_tile(game, "./img/exit.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./img/player/front.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
	}
	else
	{
		if (matrix[pos.x + 1][pos.y] == 'C')
		{
			matrix[pos.x + 1][pos.y] = '0';
			game->map->c_count -= 1;
		}	
		put_tile(game, "./img/floor.xpm", pos.y * PIXEL, pos.x * PIXEL);
		put_tile(game, "./img/player/front.xpm", pos.y * PIXEL, (pos.x + 1) * PIXEL);
	}
	game->move_count += 1;
	game->map->p_position.x += 1;
	ft_printf("Movement count: %i\n", game->move_count);
}

int	key_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		free_structs(game);
		exit (0);
	}
/* 	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		game->move_count += 1;
		ft_printf("Movement count: %i\n", game->move_count);
	}
 	if (keysym == XK_D || keysym == XK_D || keysym == XK_Right)
	{
		game->move_count += 1;
		ft_printf("Movement count: %i\n", game->move_count);
	} */
	if (keysym == XK_W || keysym == XK_W || keysym == XK_Up)
		move_up(game);
	if (keysym == XK_S || keysym == XK_s ||keysym == XK_Down )
		move_down(game);
	return (0);
}

int	close_window(t_game *game)
{
	free_structs(game);
	exit (0);
}
