/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:51:12 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/11 15:58:35 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	init_philo(t_all *all)
{
	all->philo = malloc(sizeof(t_data) * all->data->nb_of_philo);
	if (all->philo == NULL)
		return (1);
	all->philo->pid = malloc(sizeof(pid_t) * all->data->nb_of_philo);
	if (all->philo->pid == NULL)
		return (1);
	all->data->flag = 0;
	all->philo->eat_count = all->data->nb_of_meals;
	all->philo->args = all->data;
	all->philo->sems = all->lock;
	return (0);
}

int	init_sems(t_all *all)
{
	all->lock = malloc(sizeof(t_sema));
	if (all->lock == NULL)
		return (put_err("Memory's not been allocated", false));
	sem_unlink("output");
	all->lock->output = sem_open("output", O_CREAT, 0644, 1);
	if (all->lock->output == SEM_FAILED)
		return (put_err("Semaphore failsed to open", 0));
	sem_unlink("forkes");
	all->lock->forks = sem_open("forks", O_CREAT, 0644, all->data->nb_of_philo / 2);
	if (all->lock->forks == SEM_FAILED)
		return (put_err("Semaphore failsed to open", 0));
	return (0);
}

