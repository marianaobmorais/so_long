# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 15:34:43 by mariaoli          #+#    #+#              #
#    Updated: 2024/08/05 18:56:08 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
B_NAME = bonus_so_long


LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

MLIBX = ./minilibx-linux/libmlx.a
MLIBX_DIR = ./minilibx-linux

SRCS = main.c \
		check_args.c check_map.c \
		init.c init_map_utils.c \
		hook_functions.c \
		press_left.c press_right.c press_up.c press_down.c \
		free_functions.c \
		render.c

B_SRCS = bonus_main.c \
			bonus_check_args.c bonus_check_map.c \
			bonus_init.c bonus_init_map_utils.c \
			bonus_hook_functions.c \
			bonus_press_left.c bonus_press_right.c bonus_press_up.c bonus_press_down.c \
			bonus_free_functions.c \
			bonus_render.c \
			bonus_move_rabbit.c #######

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm 

RM = rm -f

$(NAME): $(LIBFT) $(MLIBX) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

all: $(NAME) bonus

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(MLIBX):
	$(MAKE) -C $(MLIBX_DIR)

bonus: $(B_NAME)

$(B_NAME): $(LIBFT) $(MLIBX) $(B_SRCS)
	$(CC) $(CFLAGS) $(B_SRCS) $(LIBFT) $(MLXFLAGS) -o $(B_NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLIBX_DIR)

fclean: clean
	$(RM) $(NAME) $(B_NAME) $(LIBFT) $(MLIBX)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus