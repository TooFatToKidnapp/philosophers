/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:50:59 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/13 13:13:50 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	free_all(t_all *all)
{
	sem_unlink("output");
	sem_unlink("forks");
	sem_close(all->lock->output);
	sem_close(all->lock->forks);
	free(all->lock);
	free(all->philo->pid);
	free(all->philo);
}

void	start_act(t_philo *phil)
{
	pthread_t	dead_flag;

	phil->start_time = get_time();
	phil->last_meal = get_time();
	pthread_create(&dead_flag, NULL, check_death, (void *)phil);
	pthread_detach(dead_flag);
	while (1)
	{
		if (phil->eat_count != 0)
		{
			eating(phil);
			phil->eat_count--;
			output(phil, "is sleeping");
			is_sleep(phil->args->time_to_sleep);
			output(phil, "is thinking");
		}
		else
			exit (0);
	}
}

void	wait_loop(t_all *all)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (i < all->data->nb_of_philo)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			j = 0;
			while (j < all->data->nb_of_philo)
			{
				kill(all->philo->pid[j], SIGTERM);
				j++;
			}
		}
		i++;
	}
}

int	init_process(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nb_of_philo)
	{
		all->philo->pid[i] = fork();
		if (all->philo->pid[i] == 0)
		{
			all->philo->philo_id = i + 1;
			start_act(all->philo);
		}
		else if (all->philo->pid[i] == -1)
			return (put_err("Can't create a process\n", 0));
		i++;
	}
	wait_loop(all);
	return (0);
}
