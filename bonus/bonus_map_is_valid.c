/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:49:19 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/10 17:18:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

int	map_is_rectangle(t_map *map)
{
	int	row;
	int	collumn;

	row = 0;
	while (map->matrix[row])
	{
		collumn = 0;
		while (map->matrix[row][collumn])
			collumn++;
		if (map->column != collumn)
			return (0);
		row++;
	}
	return (1);
}

int	map_is_closed(t_map *map)
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
			return (0);
		i++;
	}
	i = 1;
	while (i < row - 1)
	{
		if (mtrx[i][0] != '1' || mtrx[i][col - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_path(t_map *tmp, int x, int y)
{
	if (x < 0 || y < 0 || x >= tmp->row || y >= tmp->column)
		return (0);
	if (tmp->matrix[x][y] == 'E')
		tmp->e_count--;
	if (tmp->c_count == 0 && tmp->e_count == 0)
		return (1);
	if (tmp->matrix[x][y] == '1')
		return (0);
	if (tmp->matrix[x][y] == 'C' && tmp->c_count > 0)
		tmp->c_count--;
	tmp->matrix[x][y] = '1';
	if (check_path(tmp, x - 1, y) || check_path(tmp, x + 1, y)
		|| check_path(tmp, x, y - 1) || check_path(tmp, x, y + 1))
		return (1);
	return (0);
}

int	path_is_valid(t_map *map)
{
	t_map	tmp;

	init_tmp(&tmp, map);
	if (!tmp.matrix)
		return (ft_printf(ERROR_MALLOC), 0);
	if (!check_path(&tmp, map->p_position.x, map->p_position.y))
	{
		free_map_matrix(tmp.matrix);
		return (0);
	}
	free_map_matrix(tmp.matrix);
	return (1);
}

int	map_is_valid(t_map *map)
{
	if (map->row < 3 || map->column < 3)
		return (ft_printf(ERROR_COL_ROW), 0);
	if (!map_is_rectangle(map))
		return (ft_printf(ERROR_RECTANGLE), 0);
	if (!map_is_closed(map))
		return (ft_printf(ERROR_WALLS), 0);
	if (map->p_count != 1)
		return (ft_printf(ERROR_PLAYER), 0);
	if (map->c_count < 1)
		return (ft_printf(ERROR_COLLECT), 0);
	if (map->e_count != 1)
		return (ft_printf(ERROR_EXIT), 0);
	if (!path_is_valid(map))
		return (ft_printf(ERROR_PATH), 0);
	return (1);
}
