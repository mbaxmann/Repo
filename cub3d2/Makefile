# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 09:36:11 by mbaxmann          #+#    #+#              #
#    Updated: 2020/09/05 11:52:03 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS    =       ${SRCS:.c=.o}

SRCS    =       srcs/ft_cub3d.c srcs/ft_init.c srcs/ft_check_map.c      srcs/ft_check_map2.c srcs/ft_init2.c srcs/ft_list.c srcs/ft_event.c     srcs/ft_raycasting.c srcs/ft_display.c srcs/ft_raycasting_2.c srcs/ft_raycasting_3.c srcs/ft_event_2.c srcs/ft_display_2.c srcs/ft_load_sprite.c srcs/ft_load_sprite_2.c srcs/ft_free_data.c srcs/ft_loop.c srcs/ft_save_img.c srcs/ft_free_data_2.c srcs/ft_init_3.c srcs/ft_load_sprite_3.c srcs/ft_init_4.c

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       cub3D

LINK	=	-lm -lXext -lX11 -lft -lmlx -lbsd

LIB     =       libft/libft.a mlx/libmlx.a

RM      =       rm -rf

LIB_PATH	=	-L ./libft/ -L ./mlx

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		make -C libft
		make -C mlx
		${CC} ${LIB_PATH} -o ${NAME} ${OBJS} ${LINK}

clean:
	make clean -C libft
	make clean -C mlx
	${RM} ${OBJS}

fclean:         clean
	make fclean -C libft
	make clean -C mlx
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

