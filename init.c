/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:27:08 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/27 20:22:01 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->image = NULL;
	game->map = NULL;
	game->move_count = 0;
}

t_map	init_map(int fd)
{
	t_map	map;
	
	map.matrix = get_matrix(fd);
	if (!map.matrix)
		return (map);
	map.row = count_rows(map.matrix);
	map.column = ft_strlen(map.matrix[0]);
	map.p_position = player_position(map.matrix);
	map.p_count = count_characters(map.matrix, 'P');
	map.c_count = count_characters(map.matrix, 'C');
	map.e_count = count_characters(map.matrix, 'E');
	return (map);
}