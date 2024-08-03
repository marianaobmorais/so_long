/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/03 19:56:18 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

/* void	move_rabbit(t_game *game)
{
	
} */

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	if (!check_args(ac, av))
		return (EXIT_FAILURE);
	map = init_map(av[1]);
	if (!map)
		return (EXIT_FAILURE);
	game = init_game(map);
	if (!game)
		return (ft_printf(ERROR_GAME_INIT), EXIT_FAILURE);
	render(game);
	//move_rabbit(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, key_input, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
