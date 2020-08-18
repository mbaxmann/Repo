# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 09:36:11 by mbaxmann          #+#    #+#              #
#    Updated: 2020/08/18 10:39:44 by mbaxmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ${SRCS:.c=.o}

SRCS =	srcs/ft_cub3d.c srcs/ft_init.c srcs/ft_check_map.c	srcs/ft_check_map2.c srcs/ft_init2.c srcs/ft_list.c srcs/ft_event.c	srcs/ft_raycasting.c srcs/ft_display.c srcs/ft_raycasting_2.c srcs/ft_raycasting_3.c srcs/ft_event_2.c

HEADERS = include/cub3d.h include/init.h

CC = gcc 

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
			${CC} -o ${NAME} ${FLAGS} ${FRAMEWORK} ${OBJS} -L. ${LIB} -g

clean:
	make clean -C libft
	make clean -C mlx
	${RM} ${OBJS}

fclean:		clean
	make fclean -C libft
	${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
