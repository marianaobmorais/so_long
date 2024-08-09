/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:18:43 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 15:16:03 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

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

int	random_move(t_game *game)
{
	time_t	r_curr_time;
	time_t	c_curr_time;

	r_curr_time = time(NULL);
	if (r_curr_time - game->r_move_time >= RABBIT_INTERVAL)
	{
		move_rabbits(game);
		game->r_move_time = r_curr_time;
	}
	c_curr_time = time(NULL);
	if (c_curr_time - game->c_move_time >= KNIGHT_INTERVAL)
	{
		move_knights(game);
		game->c_move_time = c_curr_time;
	}
	return (0);
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
	mlx_loop_hook(game->mlx, random_move, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, key_input, game);
	mlx_hook(game->window, DestroyNotify, NoEventMask, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
