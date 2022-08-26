# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:13:27 by aabdou            #+#    #+#              #
#    Updated: 2022/04/13 13:19:24 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

NAME_BONUS = philosophers_bonus

HEADER = philo/philosophers.h

HEADER_B = philo_bonus/philosophers_bonus.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread #-g -fsanitize=thread

SRC =	philo/death.c\
		philo/eat_and_sleep.c\
		philo/philosophers.c\
		philo/thread.c\
		philo/utils.c\
		philo/main.c\

SRC_B =	philo_bonus/death_bonus.c\
		philo_bonus/main_bonus.c\
		philo_bonus/philosophers_bonus.c\
		philo_bonus/processes_bonus.c\
		philo_bonus/sleep_and_eat_bonus.c\
		philo_bonus/util_bonus.c\

OBJ = $(SRC:%.c=%.o)

OBJ_B = $(SRC_B:%.c=%.o)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $<
	
%.o : %.c $(HEADER_B)
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_B) $(HEADER_B)
	$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_BONUS)

clean:
	@rm -f philo/*.o philo_bonus/*.o

fclean: clean
	@rm -f philosophers philosophers_bonus

re: fclean all
