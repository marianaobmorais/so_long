/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/30 21:04:21 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	map = init_map(av[1]);
	if (!map || !map->matrix)
		exit(EXIT_FAILURE);
	if (!check_map(map))
	{
		free_map_matrix(map->matrix);
		return (EXIT_FAILURE);
	}
	game = init_game(map);
	if (!game->mlx || !game->window || !game->img)
	{
		free_structs(game);
		return (ft_printf(ERROR_GAME_INIT), EXIT_FAILURE);
	}
	render(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, key_input, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
