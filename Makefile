# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 15:34:43 by mariaoli          #+#    #+#              #
#    Updated: 2024/08/02 17:37:04 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

MLIBX = ./minilibx-linux/libmlx.a
MLIBX_DIR = ./minilibx-linux

SRCS = main.c check_args.c check_map.c init.c init_map_utils.c hook_functions.c move_left.c move_right.c move_up.c move_down.c free_functions.c render.c

#OBJS = $(SRCS:.c=.o) 

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm 


RM = rm -f

$(NAME): $(LIBFT) $(MLIBX) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

all: libraries $(NAME) #bonus

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(MLIBX):
	$(MAKE) -C $(MLIBX_DIR)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -0 $@

clean:
#	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLIBX_DIR) libmlx_Linux.a

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLIBX)
	$(MAKE) fclean -C $(LIBFT_DIR)

#bonus:

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re libraries #bonus