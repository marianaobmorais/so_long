# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 15:34:43 by mariaoli          #+#    #+#              #
#    Updated: 2024/08/06 15:46:12 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
B_NAME = bonus_so_long

SRCS_DIR = ./srcs
BONUS_DIR = ./bonus

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

MLIBX = ./minilibx-linux/libmlx.a
MLIBX_DIR = ./minilibx-linux

SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/check_args.c \
		$(SRCS_DIR)/check_map.c \
		$(SRCS_DIR)/init.c \
		$(SRCS_DIR)/init_map_utils.c \
		$(SRCS_DIR)/hook_functions.c \
		$(SRCS_DIR)/press_left.c \
		$(SRCS_DIR)/press_right.c \
		$(SRCS_DIR)/press_up.c \
		$(SRCS_DIR)/press_down.c \
		$(SRCS_DIR)/free_functions.c \
		$(SRCS_DIR)/render.c

B_SRCS = $(BONUS_DIR)/bonus_main.c \
			$(BONUS_DIR)/bonus_check_args.c \
			$(BONUS_DIR)/bonus_check_map.c \
			$(BONUS_DIR)/bonus_init.c \
			$(BONUS_DIR)/bonus_init_map_utils.c \
			$(BONUS_DIR)/bonus_hook_functions.c \
			$(BONUS_DIR)/bonus_press_left.c \
			$(BONUS_DIR)/bonus_press_right.c \
			$(BONUS_DIR)/bonus_press_up.c \
			$(BONUS_DIR)/bonus_press_down.c \
			$(BONUS_DIR)/bonus_free_functions.c \
			$(BONUS_DIR)/bonus_render.c \
			$(BONUS_DIR)/bonus_move_rabbit.c #######

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