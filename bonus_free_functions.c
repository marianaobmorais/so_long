/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_free_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:24:54 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/03 18:11:29 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	free_map_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_structs(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			if (game->map->matrix)
				free_map_matrix(game->map->matrix);
			free(game->map);
		}
		if (game->img)
		{
			if (game->img->img_ptr)
				mlx_destroy_image(game->mlx, game->img->img_ptr);
			free(game->img);
		}
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}
