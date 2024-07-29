/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:27:08 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/29 19:19:31 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_tmp(t_map *tmp, t_map map)
{
	int	i;

	i = 0;
	tmp->matrix = malloc(sizeof(char *) * (map.row + 1));
	if (!tmp->matrix)
		return ;
	while (i < map.row)
	{
		tmp->matrix[i] = ft_strdup(map.matrix[i]);
		if (!tmp->matrix[i])
		{
			while (i > 0)
				free(tmp->matrix[--i]);
			free(tmp->matrix);
			return ;
		}
		i++;
	}
	tmp->matrix[i] = NULL;
	tmp->row = map.row;
	tmp->column = map.column;
	tmp->p_position = map.p_position;
	tmp->p_count = map.p_count;
	tmp->c_count = map.c_count;
	tmp->e_count = map.e_count;
}

t_image	*init_image(t_game *game)
{
	game->image = (t_image *)malloc(sizeof(t_image));
	if (!game->image)
	{
		free_structs(game);
		return (NULL);
	}
	game->image->img_ptr = mlx_new_image(game->mlx, 1, 1/* (game->map->column * PIXEL), (game->map->row * PIXEL) */);
	if (game->image->img_ptr == NULL)
	{
		free_structs(game);
		return (NULL);
	}
	return (game->image);
}

void	init_game(t_map *map, t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf(ERROR_MLX);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
	game->window = mlx_new_window(game->mlx, (map->column * PIXEL), (map->row * PIXEL), "so_long");
	if (!game->window)
	{
		ft_printf(ERROR_WINDOW);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
	game->image = init_image(game);
	game->map = map;
	game->move_count = 0;
}
