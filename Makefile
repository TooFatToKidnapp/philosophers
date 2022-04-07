# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:13:27 by aabdou            #+#    #+#              #
#    Updated: 2022/04/07 01:14:34 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philosophers/philosophers.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	philosophers/death.c\
		philosophers/eat_and_sleep.c\
		philosophers/philosophers.c\
		philosophers/thread.c\
		philosophers/utils.c\
		philosophers/main.c\

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f philosophers/*.o

fclean: clean
	@rm -f philo

re: fclean all
