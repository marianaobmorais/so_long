/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/05 19:48:35 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

/* void	move_rabbit(t_game *game)
{
	
} */

void	print_move(t_game *game)
{
	char	*count;
	char	*s;
	char	*font;

	font = "-misc-fixed-bold-r-normal--18-120-100-100-c-90-iso8859-9";
	count = ft_itoa(game->move_count);
	s = ft_strjoin("Move count: ", count);
	mlx_put_image_to_window(game->mlx, game->window,
		game->img->block_ptr, 14, 5);
	mlx_set_font(game->mlx, game->window, font);
	mlx_string_put(game->mlx, game->window, 20, 20, 0xFFFFFF, s);
	free(count);
	free(s);
}

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
	srand(time(NULL));
	render(game);
	print_move(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, key_input, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
