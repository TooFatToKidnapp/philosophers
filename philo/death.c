/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:15:37 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/30 21:59:56 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int if_dead(t_philo *philo)
{
    long hunger_time;

    hunger_time = get_time() - philo->last_meal;
    if(philo->args->time_to_die < hunger_time)
    {
        pthread_mutex_lock(&philo->mutex->output);
        printf("%ld\t The philo %d id dead\n", get_time() - philo->start_time, philo->philo_id);
        philo->args->flag = 1;
        return (0);
    }
    return (1);
}

void *check_death(void *info)
{
    t_all   *all;
    int     i;
    int     meals_count;
    
    all = (t_all*)info;
    while(1)
    {
        i = 0;
        meals_count = 0;
        while (i < all->data->nb_of_philo)
        {
            if (!if_dead(&all->philo[i]))
                return (NULL);
            meals_count += all->philo[i].eat_count;
            i++;
        }
        if (meals_count == 0)
        {
            pthread_mutex_lock(&all->lock->output);
            return (NULL);
        }
    }
}