/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:05:41 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/27 13:15:07 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_and_destroy(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nb_of_philo)
	{
		pthread_mutex_destroy(all->philo[i].left_fork);
		pthread_mutex_destroy(all->philo[i].right_fork);
		free(all->philo[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&all->lock->output);
	free(all->lock->forks);
	free(all->lock);
	free(all->philo);
}

void	*start(void *philo)
{
	t_philo	*data;

	data = (t_philo *)philo;
	if (pthread_mutex_lock(data->last_meal_lock) == 0)
		data->last_meal = get_time();
	pthread_mutex_unlock(data->last_meal_lock);
	pthread_detach(data->thread);
	while (1)
	{
		if (data->eat_count != 0)
		{
			eating(data);
			data->last_meal = get_time();
			if (pthread_mutex_lock(data->eat_count_lock) == 0)
				data->eat_count--;
			pthread_mutex_unlock(data->eat_count_lock);
			is_sleep(data->args->time_to_eat);
			pthread_mutex_unlock(data->left_fork);
			pthread_mutex_unlock(data->right_fork);
			output(data, "is sleeping");
			is_sleep(data->args->time_to_sleep);
			output(data, "is thinking");
		}
		else
			break ;
	}
	return (NULL);
}

int	make_thread(t_all *info, int flag, int i)
{
	if (info->philo[i].philo_id % 2 == flag)
	{
		info->philo[i].start_time = info->data->time;
		info->philo[i].mutex = malloc(sizeof(t_mutex));
		if (!info->philo[i].mutex)
		{
			destroy_mutex(info);
			free(info->lock);
			free(info->lock->forks);
			return (put_err("Memory is not allocated", false));
		}
		if (pthread_create(&info->philo[i].thread, NULL,
				&start, &info->philo[i]) != 0)
		{
			destroy_mutex(info);
			free(info->lock);
			free(info->lock->forks);
			return (put_err("Thread can't be created", false));
		}
	}
	usleep(30);
	return (0);
}

int	thread(t_all *info)
{
	int	i;

	i = -1;
	info->data->time = get_time();
	while (++i < info->data->nb_of_philo)
		make_thread(info, 0, i);
	i = -1;
	usleep(50);
	while (++i < info->data->nb_of_philo)
		make_thread(info, 1, i);
	if (pthread_create(&info->death, NULL, &check_death, info) != 0)
		return (put_err("Thread can't be created", false));
	if (pthread_join(info->death, NULL) != 0)
		return (put_err("Threaf can't be joined", 0));
	free_and_destroy(info);
	return (0);
}
