/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:19:25 by mariaoli          #+#    #+#             */
/*   Updated: 2024/08/10 17:18:06 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

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
# define GAME_LOST "The killer rabbit caught you. You lose!\n"
# define GAME_LOST_C "The killer rabbit caught one of your knights. You lose!\n"
# define GAME_LOST_E "The killer rabbit ate the Holy Grail. You lose!\n"

# define PIXEL 32

# define RABBIT_INTERVAL 0.04
# define KNIGHT_INTERVAL 0.08

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
	t_point	e_position;
	t_point	p_position;
	int		p_count;
	int		c_count;
	int		e_count;
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	void	*block_ptr;
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
	time_t	r_move_time;
	time_t	c_move_time;
}	t_game;

int		check_args(int ac, char **av);
t_map	*init_map(char *filename);
void	init_tmp(t_map *tmp, t_map *map);
t_game	*init_game(t_map *map);
char	**get_matrix(int fd);
int		count_rows(char **matrix);
t_point	char_position(char **matrix, char c);
int		count_characters(char **matrix, char c);
int		map_is_valid(t_map *map);
int		map_is_rectangle(t_map *map);
int		map_is_closed(t_map *map);
int		path_is_valid(t_map *map);
int		check_path(t_map *tmp, int x, int y);
int		close_window(t_game *game);
void	render(t_game *game);
void	put_tile(t_game *game, char *path, int x, int y);
void	free_map_matrix(char **matrix);
void	free_structs(t_game *game);
void	free_map_struct(t_map *map);
int		key_input(int keysym, t_game *game);
void	press_up(t_game *game);
void	press_down(t_game *game);
void	press_left(t_game *game);
void	press_right(t_game *game);
void	print_move(t_game *game);
void	*init_count_block(t_game *game);
int		random_move(t_game *game);
t_point	*find_animated(char **matrix, int *count, char c);
void	move_rabbits(t_game *game);
void	move_knights(t_game *game);
int		rabbit_left(t_game *game, t_point pos);
int		rabbit_right(t_game *game, t_point pos);
int		rabbit_up(t_game *game, t_point pos);
int		rabbit_down(t_game *game, t_point pos);
int		game_over(char **matrix, int x, int y, int c_count);

#endif