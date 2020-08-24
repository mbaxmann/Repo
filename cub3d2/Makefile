# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 09:36:11 by mbaxmann          #+#    #+#              #
#    Updated: 2020/08/24 17:14:31 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ${SRCS:.c=.o}

SRCS =	srcs/ft_cub3d.c srcs/ft_init.c srcs/ft_check_map.c	srcs/ft_check_map2.c srcs/ft_init2.c srcs/ft_list.c srcs/ft_event.c	srcs/ft_raycasting.c srcs/ft_display.c srcs/ft_raycasting_2.c srcs/ft_raycasting_3.c srcs/ft_event_2.c srcs/ft_display_2.c srcs/ft_load_sprite.c

HEADERS = include/cub3d.h include/init.h

CC = clang

FLAGS = -Wall -Wextra -Werror 

FRAMEWORK = -framework OpenGL -framework AppKit

NAME = cub3d

LIB = libft/libft.a mlx/libmlx.a

RM = rm -rf

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C libft
			make -C mlx
			${CC} -o ${NAME} ${FLAGS} ${FRAMEWORK} ${OBJS} -L. ${LIB}
linux:		${OBJS}
			make -C libft
			${CC} -o cub3d_linux ${FLAGS} ${OBJS} -L. libft/libft.a mlx_linux/libmlx_Linux.a -lm -lXext -lX11

clean:
	make clean -C libft
	make clean -C mlx
	${RM} ${OBJS}

fclean:		clean
	make fclean -C libft
	${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
