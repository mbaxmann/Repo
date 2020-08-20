# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 13:34:50 by mbaxmann          #+#    #+#              #
#    Updated: 2020/01/24 13:56:23 by mbaxmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ${SRCS:.c=.o}

SRCS =	ft_p_itoa.c ft_display.c ft_display2.c ft_display3.c ft_hexa_itoa.c ft_print_function.c ft_printf.c ft_printf_getarg.c ft_printf_getarg2.c ft_printf_list.c
HEADERS = ft_printf.h

CC = cc -I

NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -g

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS} ${HEADERS}
clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
