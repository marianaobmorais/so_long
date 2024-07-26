/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:49:19 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/26 19:19:55 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_file_rows(char *file_name, t_map *map)
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
		free(map_array);
		line = get_next_line(fd);
		map_array = tmp;
		map->row++;
	}
	close(fd);
	if (map->row < 3)
	{
		free(map_array);
		return (ft_printf("Error: map requires at least 3 rows\n"), NULL);
	}
	return (map_array);
}

int	check_array(char *array)
{
	int		i;
	
	i = 0;
	while (array[i])
	{
	 	if (array[i] == '\n' && array[i + 1] == '\n')
			return (ft_printf("Error: map has an empty line\n"), 0);
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
			j++;
		if (len != j)
			return (ft_printf("Error: map is not a rectangle\n"), 0);
		i++;
	}
	if (len < 3)
		return (ft_printf("Error: map requires at least 3 columns\n"), 0);
	map->column = len;
	return (1);
}

void	get_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == 'P')
			{
				map->player++;
				map->p_position.x = i;
				map->p_position.y = j;
			}
			if (map->matrix[i][j] == 'C')
				map->collect++;
			if (map->matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
}

int	check_characters(t_map *map)
{
	get_characters(map);
	if (map->player != 1)
		return (ft_printf("Error: you must have only one player\n"), 0);
	if (map->collect < 1)
		return (ft_printf("Error: you need at least one collectable\n"), 0);
	if (map->exit != 1)
		return (ft_printf("Error: you must have only one exit\n"), 0);
	return (1);
}

int	make_map_matrix(char *map_array, t_map *map)
{
	map->matrix = ft_split(map_array, '\n');
	free(map_array);
	if (!map->matrix)
		return (ft_printf("Error: memory allocation failed in ft_split\n"), 0);
	return (1);
}

int	closed_map(t_map *map)
{
	int		i;
	int		col;
	int		row;
	char	**mtrx;

	mtrx = map->matrix;
	col = map->column;
	row = map->row;
	i = 0;
	while (i < col)
	{
		if (mtrx[0][i] != '1' || mtrx[row - 1][i] != '1')
			return (ft_printf("Error: map is not surrounded by walls\n"), 0);
		i++;
	}
	i = 1;
	while (i < row - 1)
	{
		if (mtrx[i][0] != '1' || mtrx[i][col - 1] != '1')
			return (ft_printf("Error: map is not surrounded by walls\n"), 0);
		i++;
	}
	return (1);
}

void	flood_fill(char **tmp, int row, int col, t_pos begin)
{
	char	c;
	t_pos	pos;

	c = tmp[begin.y][begin.x];
	tmp[begin.y][begin.x] = 'F';

	flood_fill();
}

int	check_path(t_map *map)
{
	int		i;
	char	**tmp;

	i = 0;
	while (map->matrix[i])
	{
		tmp[i] = ft_strdup(map->matrix[i]);
		i++;
	}
	flood_fill(tmp, map->row, map->column, map->p_position);
	free_map_matrix(tmp);
	return (1);
}

int valid_matrix(char *file_name, t_map *map)
{
	char	*map_array;

	map_array = read_file_rows(file_name, map);
	if (!map_array)
		return (0);
	if (!check_array(map_array))
		return (free(map_array), 0);
	if (!make_map_matrix(map_array, map))
		return (0);
	if (!check_columns(map))
		return(free_map_matrix(map->matrix), 0);
	if (!check_characters(map))
		return(free_map_matrix(map->matrix), 0);
	if (!closed_map(map))
		return(free_map_matrix(map->matrix), 0);
	if (!check_path(map))
		return(free_map_matrix(map->matrix), 0);
	return (1);
}

t_map	*get_map(char *file_name, t_map *map)
{
	if (!valid_matrix(file_name, map))
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}