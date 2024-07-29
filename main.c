/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/29 19:07:00 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;
	t_game	game;
	//t_image	image;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	map = init_map(fd);
	if (!map.matrix)
		exit(EXIT_FAILURE);
	if (!check_map(map))
	{
		free_map_matrix(map.matrix);
		exit(EXIT_FAILURE);
	}
	init_game(&map, &game);
	if (!game.mlx || !game.window || !game.image)
		exit(EXIT_FAILURE);
	mlx_hook(game.window, KeyPress, KeyPressMask, key_input, &game);
	mlx_hook(game.window, DestroyNotify, NoEventMask, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
