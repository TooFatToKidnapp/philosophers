/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:11:26 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/07 01:18:02 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<pthread.h>
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include<time.h>
# include <sys/time.h>

typedef struct mutex
{
	pthread_mutex_t	output;
	pthread_mutex_t	*forks;
}					t_mutex;

typedef struct data
{
	long	time;
	int		flag;
	int		nb_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_of_meals;
}			t_data;

typedef struct philo
{
	int				philo_id;
	int				eat_count;
	long			start_time;
	long			last_meal;
	t_data			*args;
	t_mutex			*mutex;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

typedef struct all
{
	pthread_t	death;
	t_mutex		*lock;
	t_philo		*philo;
	t_data		*data;
}				t_all;

long	get_time(void);
int		eating(t_philo *philo);
void	is_sleep(long wait_time);
int		thread(t_all *info);
void	destroy_mutex(t_all *all);
void	output(t_philo *philo, char *str);
void	*check_death(void *info);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		put_err(char *str, bool i);
int		parsing_arg(char **av);

int		make_thread(t_all *info, int flag, int i);
int		init_mutex(t_all *info);
int		if_dead(t_philo *philo);
void	*start(void *philo);
void	free_and_destroy(t_all *all);
int		init_philo(t_all *info);

#endif
