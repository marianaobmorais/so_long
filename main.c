/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/24 19:49:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* typedef struct s_image
{
	void	*img;
	char	*path;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_image	*image;
	int		move_count;
}	t_game; */

int key_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(game->mlx, game->image->img_ptr);
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit (0);
	}
	if (keysym == XK_A || keysym == XK_D || keysym == XK_W || keysym == XK_S ||
		keysym == XK_a || keysym == XK_d || keysym == XK_w || keysym == XK_s)
	{
		game->move_count += 1;
		ft_printf("Movement count: %i\n", game->move_count);
	}
	if (keysym == XK_Left || keysym == XK_Right || keysym == XK_Up || keysym == XK_Down)
	{
		game->move_count += 1;
		ft_printf("Movement count: %i\n", game->move_count);
	}
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image->img_ptr);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->image = NULL;
	game->move_count = 0;
}

int main(int ac, char **av)
{
	t_game game;
	t_image image;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	if (!check_map(av[1]))
		return (EXIT_FAILURE);
	init_game(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (EXIT_FAILURE);
	game.window = mlx_new_window(game.mlx, 600, 400, "so_long");
	if (game.window == NULL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (EXIT_FAILURE);
	}
	image.img_ptr = mlx_new_image(game.mlx, 600, 400);
	if (image.img_ptr == NULL)
	{
		mlx_destroy_window(game.mlx, game.window);
		mlx_destroy_display(game.mlx);
		return (EXIT_FAILURE);
	}
	
/* 	image.path = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len, &image.endian);
	image.x = 0;
	image.y = 0; */

	game.image = &image;

	mlx_hook(game.window, KeyPress, KeyPressMask, key_input, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, close_window, &game);
	mlx_loop(game.mlx);

	return (0);
}