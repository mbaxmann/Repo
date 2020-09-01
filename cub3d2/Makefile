# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 09:36:11 by mbaxmann          #+#    #+#              #
#    Updated: 2020/09/01 12:32:19 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)

SRCS =	srcs/ft_cub3d.c srcs/ft_init.c srcs/ft_check_map.c	srcs/ft_check_map2.c srcs/ft_init2.c srcs/ft_list.c srcs/ft_event.c	srcs/ft_raycasting.c srcs/ft_display.c srcs/ft_raycasting_2.c srcs/ft_raycasting_3.c srcs/ft_event_2.c srcs/ft_display_2.c srcs/ft_load_sprite.c srcs/ft_load_sprite_2.c srcs/ft_free_data.c srcs/ft_loop.c srcs/ft_save_img.c srcs/ft_free_data_2.c srcs/ft_init_3.c srcs/ft_load_sprite_3.c

HEADERS = include/ft_cub3d.h include/ft_init.h

CC = clang

FLAGS = -Wall -Wextra -Werror 

LINK = -lm -lXext -lX11 -lft -lmlx

NAME = cub3d

LIB = libft/libft.a mlx/libmlx.a

PATH = -L ./libft/ -L ./mlx

RM = rm -rf

all: 	$(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		make -C libft
		make -C mlx
		$(CC) $(PATH) -o $(NAME) $(OBJS) $(LINK)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean:		clean
	make fclean -C libft
	make clean -C mlx
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
