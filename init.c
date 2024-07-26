/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:27:08 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/26 19:06:17 by mariaoli         ###   ########.fr       */
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

void	init_map(t_map *map)
{
	map->matrix = NULL;
	map->row = 0;
	map->column = 0;
	map->p_position.x = 0;
	map->p_position.y = 0;
	map->player = 0;
	map->collect = 0;
	map->exit = 0;
	map->enemy = 0;
}