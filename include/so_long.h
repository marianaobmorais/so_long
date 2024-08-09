/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:19:25 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/08 13:37:10 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define ERROR_GAME_INIT "Error: game initialization failed\n"
# define ERROR_NO_ARG "Error: no arguments"
# define ERROR_EMPTY_LINE "Error: map has an empty line\n"
# define ERROR_CHARS "Error: map has invalid characters.\
 Allowed characters: 0, 1, P, C, E\n"
# define ERROR_MALLOC "Error: memory allocation failed\n"
# define ERROR_COL_ROW "Error: map has less than 3 rows and/or 3 columns\n"
# define ERROR_RECTANGLE "Error: map must be a rectangle\n"
# define ERROR_WALLS "Error: map must be surrounded by walls\n"
# define ERROR_PLAYER "Error: you must have one player\n"
# define ERROR_COLLECT "Error: you need at least one collectable\n"
# define ERROR_EXIT "Error: you must have one exit\n"
# define ERROR_PATH "Error: map does not have a valid path\n"
# define ERROR_READ "Error: unsuccessfull file read\n"
# define ERROR_IMG_LOAD "Error: could not load image %s\n"
# define GAME_COMPLETE "Congratulations! You completed the game!\n"

# define PIXEL 32

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**matrix;
	int		row;
	int		column;
	t_point	p_position;
	int		p_count;
	int		c_count;
	int		e_count;
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_point	tile_pos;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_image	*img;
	int		move_count;
}	t_game;

int		check_args(int ac, char **av);
t_map	*init_map(char *filename);
void	init_tmp(t_map *tmp, t_map *map);
t_game	*init_game(t_map *map);
char	**get_matrix(int fd);
int		count_rows(char **matrix);
t_point	player_position(char **matrix);
int		count_characters(char **matrix, char c);
int		map_is_valid(t_map *map);
int		map_is_square(t_map *map);
int		map_is_closed(t_map *map);
int		path_is_valid(t_map *map);
int		close_window(t_game *game);
void	render(t_game *game);
void	put_tile(t_game *game, char *path, int x, int y);
void	free_map_matrix(char **matrix);
void	free_map_struct(t_map *map);
void	free_structs(t_game *game);
int		key_input(int keysym, t_game *game);
void	press_up(t_game *game);
void	press_down(t_game *game);
void	press_left(t_game *game);
void	press_right(t_game *game);

#endif