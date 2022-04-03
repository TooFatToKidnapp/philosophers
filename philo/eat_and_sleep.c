/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_and_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:02:12 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/03 17:52:14 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_mutex_lock(&philo->mutex->output);
	if (philo->args->flag == 1)
		return;
	else if (philo->args->flag == 0)
	{
		printf("%ld\tThe philo %d %s\n", get_time()
			- philo->start_time, philo->philo_id, str);
		pthread_mutex_unlock(&philo->mutex->output);
	}
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	output(philo, "has taken the right fork");
	pthread_mutex_lock(philo->left_fork);
	output(philo, "has taken the left fork");
	output(philo, "is eating");
	return (0);
}
