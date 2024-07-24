/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/24 16:36:38 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* typedef struct s_data
{
	void	*img;
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_data	*data;
	int		move_count;
}	t_game; */

int key_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(game->mlx, game->data->img);
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
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->data->img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->data = NULL;
	game->move_count = 0;
}

int main(void)
{
	t_game game;
	t_data data;

	init_game(&game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	game.window = mlx_new_window(game.mlx, 600, 400, "so_long");
	if (game.window == NULL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	data.img = mlx_new_image(game.mlx, 600, 400);
	if (data.img == NULL)
	{
		mlx_destroy_window(game.mlx, game.window);
		mlx_destroy_display(game.mlx);
		return (1);
	}
	
	data.path = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	data.x = 0;
	data.y = 0;

	game.data = &data;

	mlx_hook(game.window, KeyPress, KeyPressMask, key_input, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, close_window, &game);
	mlx_loop(game.mlx);

	return (0);
}