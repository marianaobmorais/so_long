/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:19:25 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/27 20:33:53 by mariaoli         ###   ########.fr       */
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

typedef	struct s_pos
{
	int	x;
	int	y;
}	t_pos;


typedef struct s_map
{
	char	**matrix;
	int		row;
	int		column;
	t_pos	p_position;
	int		p_count;
	int		c_count;
	int		e_count;
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

t_map	init_map(int fd);
void	init_game(t_game *game);


char 	**get_matrix(int fd);
int		count_rows(char **matrix);
t_pos	player_position(char **matrix);
int		count_characters(char **matrix, char c);

t_map	*get_map(char *file_name, t_map *map);

int		close_window(t_game *game);
void	free_map_matrix(char **matrix);
void	free_structs(t_game *game);

int 	key_input(int keysym, t_game *game);

#endif