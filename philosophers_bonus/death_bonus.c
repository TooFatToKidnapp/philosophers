/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:51:17 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/12 15:57:39 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

// int	if_dead(t_philo *philo)
// {
// 	long	hunger_time;

// 	hunger_time = get_time() - philo->last_meal;
// 	if (philo->args->time_to_die < hunger_time)
// 	{
// 		output(philo, "is dead");
// 		return (0);
// 	}
// 	return (1);
// }

void	*check_death(void *info)
{
	t_philo		*phil;
	int			meals_count;
	long		hunger_time;

	phil = (t_philo *)info;
	while (1)
	{
		meals_count = 0;
		hunger_time = get_time() - phil->last_meal;
		if (phil->args->time_to_die < hunger_time)
		{
			sem_wait(phil->sems->output);
			printf("%ld\tThe philo %d is dead\n", get_time() - \
			phil->start_time, phil->philo_id);
			exit (0);
		}
		meals_count += phil->eat_count;
		if (meals_count == 0)
		{
			sem_wait(phil->sems->output);
			exit (0);
		}
	}
}
