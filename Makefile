# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:12:09 by rkobelie          #+#    #+#              #
#    Updated: 2024/10/08 23:01:52 by rkobelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/checking.c src/exit_kill.c src/initialization.c src/printing.c \
		src/routine.c src/threads.c utils/atoi.c utils/get_time.c utils/init_validation.c\
		main.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
