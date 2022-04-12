/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_eat_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:51:04 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/12 15:03:00 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	is_sleep(long wait_time)
{
	long	starting_time;
	long	time_passed;

	starting_time = get_time();
	time_passed = get_time() + wait_time;
	while (time_passed > starting_time)
	{
		usleep(100);
		starting_time = get_time();
	}
}

void	output(t_philo *philo, char *str)
{
	sem_wait(philo->sems->output);
	if (philo->args->flag == 0)
		printf("%ld\tThe philo %d %s\n", get_time() - philo->start_time, \
		philo->philo_id, str);
	sem_post(philo->sems->output);
}

int	eating(t_philo *philo)
{
	sem_wait(philo->sems->forks);
	output(philo, "has taken the forks");
	output(philo, "is eating");
	philo->last_meal = get_time();
	is_sleep(philo->args->time_to_eat);
	sem_post(philo->sems->forks);
	return (0);
}
