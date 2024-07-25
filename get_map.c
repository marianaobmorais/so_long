/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:49:19 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/25 18:18:37 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_file(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	*map_array;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	map_array = NULL;
	while (line)
	{
		tmp = ft_strjoin(map_array, line);
		free(line);
		if (map_array)
			free(map_array);
		line = get_next_line(fd);
		map_array = tmp;
		map->row++;
	}
	close(fd);
	return (map_array);
}

int	check_array(char *array)
{
	int		i;
	
	i = 0;
	while (array[i])
	{
	/* 	if (array[i] == '\n' && array[i + 1] == '\n')
			return (ft_printf("Error: map has an empty line\n"), 0); */
		if (array[i] != '1' && array[i] != '0' && array[i] != 'C' && array[i] != 'E' && array[i] != 'P' && array[i] != '\n')
			return (ft_printf("Error: map can only have the following characters -> 0, 1, C, E, P\n"), 0);
		i++;
	}
	return (1);
}

int	check_columns(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map->matrix[i]);
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == 'P')
				map->player++;
			if (map->matrix[i][j] == 'C')
				map->collect++;
			if (map->matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		if (len != j)
			return (ft_printf("Error: map is not a rectangle\n"), 0);
		i++;
	}
	if (len < 3)
		return (ft_printf("Error: map requires at least 3 columns\n"), 0);
	if (map->player != 1)
		return (ft_printf("Error: you must have only one player\n"), 0);
	if (map->collect < 1)
		return (ft_printf("Error: you need at least one collectable\n"), 0);
	if (map->exit != 1)
		return (ft_printf("Error: you must have only one exit\n"), 0);
	map->column = len;
	return (1);
}

void	free_map_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
	}
	free(matrix);
}

int check_map(char *file_name, t_map *map)
{
	char	*map_array;

	map_array = read_file(file_name, map);
	if (!check_array(map_array))
	{
		free(map_array);
		exit(EXIT_FAILURE);
	}
	if (map->row < 3)
	{
		free(map_array);
		ft_printf("Error: map requires at least 3 rows\n");
		exit(EXIT_FAILURE);
	}
	map->matrix = ft_split(map_array, '\n');
	free(map_array);
	if (!map->matrix)
	{
		ft_printf("Error: memory allocation failed in ft_split\n");
		exit(EXIT_FAILURE);
	}
	if (!check_columns(map))
	{
		free_map_matrix(map->matrix);
		exit(EXIT_FAILURE);
	}
	return (1);
}

t_map	*get_map(char *file_name, t_map *map)
{
	t_map	*res;
	
	res = map;
	init_map(res);
	if (check_map(file_name, res))
		ft_printf("valid map");
	return (res);
}