/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_find_animated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:54:41 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 14:55:16 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_so_long.h"

static int	*count_animated(char **matrix, int *count, char c)
{
	int		i;
	int		j;

	*count = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				(*count)++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	get_animated(t_point *animated, char **matrix, int *count, char c)
{
	t_point	pos;
	int		i;
	int		j;

	*count = 0;
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
			{
				pos.x = i;
				pos.y = j;
				animated[(*count)++] = pos;
			}
			j++;
		}
		i++;
	}
}

t_point	*find_animated(char **matrix, int *count, char c)
{
	t_point	*animated;

	count = count_animated(matrix, count, c);
	animated = (t_point *)malloc(sizeof(t_point) * (*count));
	if (!animated)
		return (NULL);
	get_animated(animated, matrix, count, c);
	return (animated);
}
