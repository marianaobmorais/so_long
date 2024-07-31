/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:49:16 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/31 18:41:56 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, char *path, int x, int y)
{
	void	*new_img_ptr;

	new_img_ptr = mlx_xpm_file_to_image(game->mlx, path,
			&game->img->tile_pos.x, &game->img->tile_pos.y);
	if (new_img_ptr)
	{
		if (game->img->img_ptr)
		{
			mlx_destroy_image(game->mlx, game->img->img_ptr);
			game->img->img_ptr = NULL;
		}
		game->img->img_ptr = new_img_ptr;
		mlx_put_image_to_window(game->mlx, game->window, game->img->img_ptr,
			x, y);
	}
	else
		ft_printf(ERROR_IMG_LOAD, path);
}

void	render(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->column)
	{
		y = 0;
		while (y < game->map->row)
		{
			if (game->map->matrix[y][x] == '0')
				put_tile(game, "./img/floor.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == '1')
				put_tile(game, "./img/wall.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == 'C')
				put_tile(game, "./img/collect/front.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == 'E')
				put_tile(game, "./img/exit.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == 'P')
				put_tile(game, "./img/player/front.xpm", (x * PIXEL), (y * PIXEL));
			y++;
		}
		x++;
	}
}
