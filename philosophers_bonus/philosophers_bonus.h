/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:40:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/06 21:19:15 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
#define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
// typedef struct mutex
// {
// 	pthread_mutex_t	output;
// 	pthread_mutex_t	*forks;
// }					t_mutex;

// typedef struct data
// {
// 	long	time;
// 	int		flag;
// 	int		nb_of_philo;
// 	int		time_to_die;
// 	int		time_to_eat;
// 	int		time_to_sleep;
// 	int		nb_of_meals;
// }			t_data;

// typedef struct philo
// {
// 	int				philo_id;
// 	int				eat_count;
// 	long			start_time;
// 	long			last_meal;
// 	t_data			*args;
// 	t_mutex			*mutex;
// 	pthread_t		thread;
// 	pthread_mutex_t	*right_fork;
// 	pthread_mutex_t	*left_fork;
// }					t_philo;

// typedef struct all
// {
// 	t_mutex		*lock;
// 	t_philo		*philo;
// 	t_data		*data;
// }				t_all;

typedef struct sema
{
	sem_t	*output;
	sem_t	*forks;
}					t_sema;

typedef struct data
{
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
	t_sema			*sems;
	pid_t			*pid;
}					t_philo;

typedef struct all
{
	t_sema		*lock;
	t_philo		*philo;
	t_data		*data;
}				t_all;


#endif
