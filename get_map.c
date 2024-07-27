/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:49:19 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/27 20:33:35 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				map->p_count++;
				map->p_position.x = i;
				map->p_position.y = j;
			}
			if (map->matrix[i][j] == 'C')
				map->c_count++;
			if (map->matrix[i][j] == 'E')
				map->e_count++;
			j++;
		}
		i++;
	}
}

int	check_characters(t_map *map)
{
	get_characters(map);
	if (map->p_count != 1)
		return (ft_printf("Error: you must have only one player\n"), 0);
	if (map->c_count < 1)
		return (ft_printf("Error: you need at least one collectable\n"), 0);
	if (map->e_count != 1)
		return (ft_printf("Error: you must have only one exit\n"), 0);
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

int	path_is_valid(t_map *tmp, int x, int y)
{
	char	curr;
	
	if (x < 0 || y < 0 || x >= tmp->row || y >= tmp->column || tmp->matrix[x][y] == '1')
		return (0);
	if (tmp->matrix[x][y] == 'E')
	{
		if (tmp->c_count == 0)
			return (1);
		return (0);
	}
	if (tmp->matrix[x][y] == 'C')
		tmp->c_count--;
	curr = tmp->matrix[x][y];
	tmp->matrix[x][y] = '1';
	if (path_is_valid(tmp, x - 1, y) || path_is_valid(tmp, x + 1, y)
		|| path_is_valid(tmp, x, y - 1) || path_is_valid(tmp, x, y + 1))
		return (1);
	tmp->matrix[x][y] = curr;
	if (curr == 'C')
		tmp->c_count++;
	return (0);
} 


int	check_path(t_map *map)
{
	int		i;
	t_map	tmp;

	i = 0;
	tmp.matrix = malloc(sizeof(char *) * (map->row + 1));
	if (!tmp.matrix)
		return (ft_printf("Error: memory allocation failed\n"), 0);
	while (i < map->row)
	{
		tmp.matrix[i] = ft_strdup(map->matrix[i]);
		if (!tmp.matrix[i])
		{
			while (i > 0)
				free(tmp.matrix[--i]);
			free(tmp.matrix);
			return (ft_printf("Error: memory allocation failed\n"), 0);
		}
		i++;
	}
	tmp.matrix[i] = NULL;
	tmp.c_count = map->c_count;
	tmp.column = map->column;
	tmp.row = map->row;
	if (!path_is_valid(&tmp, map->p_position.x, map->p_position.y))
	{
		free_map_matrix(tmp.matrix);
		return (ft_printf("Error: map path is not valid\n"), 0);
	}
	free_map_matrix(tmp.matrix);
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