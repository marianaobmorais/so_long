/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:27:08 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/30 21:06:56 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(char *filename)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: unsuccessfull file read"), NULL);
	map = (t_map *)malloc(sizeof(t_map));
	map->matrix = get_matrix(fd);
	close(fd);
	if (!map->matrix)
		return (map);
	map->row = count_rows(map->matrix);
	map->column = ft_strlen(map->matrix[0]);
	map->p_position = player_position(map->matrix);
	map->p_count = count_characters(map->matrix, 'P');
	map->c_count = count_characters(map->matrix, 'C');
	map->e_count = count_characters(map->matrix, 'E');
	return (map);
}

void	init_tmp(t_map *tmp, t_map *map)
{
	int	i;

	i = 0;
	tmp->matrix = malloc(sizeof(char *) * (map->row + 1));
	if (!tmp->matrix)
		return ;
	while (i < map->row)
	{
		tmp->matrix[i] = ft_strdup(map->matrix[i]);
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
	tmp->row = map->row;
	tmp->column = map->column;
	tmp->p_position = map->p_position;
	tmp->p_count = map->p_count;
	tmp->c_count = map->c_count;
	tmp->e_count = map->e_count;
}

t_image	*init_image(t_game *game)
{
	game->img = (t_image *)malloc(sizeof(t_image));
	if (!game->img)
		return (NULL);
	game->img->img_ptr = mlx_new_image(game->mlx,
			(game->map->column * PIXEL), (game->map->row * PIXEL));
	if (!game->img->img_ptr)
		return (NULL);
	game->img->bpp = 0;				//These will then be updated accordingly to the *current* data address
	game->img->line_len = 0;
	game->img->endian = 0;
	game->img->addr = mlx_get_data_addr(game->img->img_ptr, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	if (!game->img->addr)
		return (NULL);
	game->img->tile_pos.x = 0;
	game->img->tile_pos.y = 0;
	return (game->img);
}

t_game	*init_game(t_map *map/* , t_game *game */)
{
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (NULL);
	game->window = mlx_new_window(game->mlx, (map->column * PIXEL), (map->row * PIXEL), "so_long");
	if (!game->window)
		return (NULL);
	game->map = map;
	game->img = init_image(game);
	if (!game->img)
		return (NULL);

	game->move_count = 0;
	return (game);
}
