/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:40:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/13 13:14:31 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

typedef struct sema
{
	sem_t	*output;
	sem_t	*forks;
}				t_sema;

typedef struct data
{
	int	death_flag;
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_meals;
}				t_data;

typedef struct philo
{
	int				philo_id;
	int				eat_count;
	long			start_time;
	long			last_meal;
	t_data			*args;
	t_sema			*sems;
	pid_t			*pid;
}				t_philo;

typedef struct s_all
{
	t_sema		*lock;
	t_philo		*philo;
	t_data		*data;
}				t_all;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		parsing_arg(char **av);
int		put_err(char *err, bool i);
int		init_sems(t_all *all);
int		init_philo(t_all *all);
void	output(t_philo *philo, char *str);
int		eating(t_philo *philo);
void	is_sleep(long time_to_wait);
void	start_act(t_philo *phil);
void	*check_death(void *all_data);
void	free_all(t_all *all);
long	get_time(void);
int		init_process(t_all *all);
void	wait_loop(t_all *all);

#endif
