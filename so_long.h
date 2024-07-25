/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:19:25 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/25 19:25:23 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define ERROR_NO_ARG "Error: no arguments"

typedef struct s_map
{
	char	**matrix;
	int		row;
	int		column;
	int		collect;
	int		exit;
	int		player;
	int		enemy;
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*path;
	int		bpp;
	int		width;
	int		height;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_image	*image;
	t_map	*map;
	int		move_count;
}	t_game;


int		check_args(int ac, char **av);
t_map	*get_map(char *file_name, t_map *map);
void	init_game(t_game *game);
void	init_map(t_map *map);
int		close_window(t_game *game);
void	free_map_matrix(char **matrix);

#endif