# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:14:51 by mbaxmann          #+#    #+#              #
#    Updated: 2020/01/24 13:56:26 by mbaxmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = ${SRCS:.c=.o}

SRCS = ft_isalnum.c    ft_isprint.c    ft_memcmp.c     ft_putchar_fd.c ft_split.c      ft_strlcat.c    ft_strncmp.c    ft_substr.c ft_atoi.c       ft_isalpha.c    ft_itoa.c       ft_memcpy.c     ft_putendl_fd.c ft_strchr.c     ft_strlcpy.c    ft_strnstr.c    ft_tolower.c ft_bzero.c      ft_isascii.c    ft_memccpy.c    ft_memmove.c    ft_putnbr_fd.c  ft_strdup.c     ft_strlen.c     ft_strrchr.c    ft_toupper.c ft_calloc.c     ft_isdigit.c    ft_memchr.c     ft_memset.c     ft_putstr_fd.c  ft_strjoin.c    ft_strmapi.c    ft_strtrim.c    get_next_line.c
HEADERS = libft.h

CC = cc -I

NAME = libft.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: 		${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	make -C ft_printf
	cp ft_printf/libftprintf.a ./$(NAME)
	ar -rcs ${NAME} ${OBJS} ${HEADERS}
clean:
	(cd ft_printf; make clean)
	${RM} ${OBJS}

fclean:		clean
	(cd ft_printf; make fclean)
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
