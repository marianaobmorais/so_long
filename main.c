/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/27 20:36:32 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	int		fd;
	t_map	map;
	t_game	game;
	t_image	image;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	map = init_map(fd);
	if (!map.matrix)
		exit(EXIT_FAILURE);

	//------------------------------------//
	init_game(&game);
	game.map = (t_map *)malloc(sizeof(t_map));
	if (game.map == NULL)
		return(ft_printf("Error: Memory allocation failed\n"), EXIT_FAILURE);
	
	game.map = get_map(av[1], game.map);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		free_structs(&game);
		return (EXIT_FAILURE);
	}
	game.window = mlx_new_window(game.mlx, 600, 400, "so_long");
	if (game.window == NULL)
	{
		free_structs(&game);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (EXIT_FAILURE);
	}
	image.img_ptr = mlx_new_image(game.mlx, 600, 400);
	if (image.img_ptr == NULL)
	{
		free_structs(&game);
		mlx_destroy_window(game.mlx, game.window);
		mlx_destroy_display(game.mlx);
		return (EXIT_FAILURE);
	}


	game.image = &image;

	mlx_hook(game.window, KeyPress, KeyPressMask, key_input, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, close_window, &game);
	mlx_loop(game.mlx);

	return (0);
}