# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:13:27 by aabdou            #+#    #+#              #
#    Updated: 2022/04/03 17:53:45 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

HEADER = philosophers.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	death.c\
		eat_and_sleep.c\
		philosophers.c\
		thread.c\
		utils.c\

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o philo

clean:
	@rm -f *.o

fclean: clean
	@rm -f philo

re: fclean all
