/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:19:25 by mariaoli          #+#    #+#             */
/*   Updated: 2024/07/24 19:53:56 by mariaoli         ###   ########.fr       */
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
	int		move_count;
}	t_game;

int	check_args(int ac, char **av);
int	check_map(char *file_name);

#endif