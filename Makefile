# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:13:27 by aabdou            #+#    #+#              #
#    Updated: 2022/04/11 15:53:51 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

NAME_BONUS = philo_bonus

HEADER = philosophers/philosophers.h

HEADER_B = philosophers_bonus/philosophers_bonus.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC =	philosophers/death.c\
		philosophers/eat_and_sleep.c\
		philosophers/philosophers.c\
		philosophers/thread.c\
		philosophers/utils.c\
		philosophers/main.c\

SRC_B =	philosophers_bonus/death_bonus.c\
		philosophers_bonus/main_bonus.c\
		philosophers_bonus/philosophers_bonus.c\
		philosophers_bonus/processes_bonus.c\
		philosophers_bonus/sleep_and_eat_bonus.c\
		philosophers_bonus/util_bonus.c\

OBJ = $(SRC:%.c=%.o)

OBJ_B = $(SRC_B:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_B) $(HEADER_B)
	$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_BONUS)

clean:
	@rm -f philosophers/*.o philosophers_bonus/*.o

fclean: clean
	@rm -f philo philo_bonus

re: fclean all
