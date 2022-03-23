# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 12:50:52 by avillar           #+#    #+#              #
#    Updated: 2022/03/23 16:26:46 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =		push_swap.c	\
			ft_split.c	\
			utils1.c	\
			parsing.c	\

SRC	=		test.c		\
			ft_split.c	\
			utils1.c	\
			parsing.c	\

CFLAG = -Wall -Wextra -Werror

FSAN = -g3 -fsanitize=address

OBJS = $(addprefix src/, ${SRC:.c=.o})

CC	= gcc

all: ft_printf/libprintf.a ${NAME}

.c.o:
	$(CC) $(CFLAG) -Ift_printf -c -I/include/includes.h $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -Lft_printf -lprintf -o $(NAME)

ft_printf/libprintf.a:
	make -C ft_printf

clean:
		rm -f ${OBJS}

fclean:	clean
	make -C ft_printf fclean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
