/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:16:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/27 19:50:03 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int init_mutex(t_all *info)
{
    int j;
    
    j = 0;
    info->lock = malloc(sizeof(t_mutex));
    if(!info->lock)
        return(put_err("Error : memory allocation\n", false));
    info->lock->forks = malloc(sizeof(pthread_mutex_t) * info->data->nb_of_philo);
	if(!info->lock->forks)
        return(put_err("Error : memory allocation\n", false));
	if(pthread_mutex_init((pthread_mutex_t *)&info->lock->output, NULL) != 0)
		return(put_err("Error : Mutex not initialized", false));
	while(j < info->data->nb_of_philo)
	{
		if(pthread_mutex_init(&info->lock->forks[j], NULL) != 0)
			return(put_err("Error : Mutex not initialized", false));
		j++;
	}
	return (0);
}

int main(int ac, char**av)
{
    t_all   info;
    
	t_data data;
    
    info.data = &data;
    if(ac < 5 || ac > 6)
        return(put_err("Error\n", true));
    if(!parsing_arg(av))
        return(put_err("Error\n", true));
    info.data->nb_of_philo = ft_atoi(av[1]);
    info.data->time_to_die = ft_atoi(av[2]);
    info.data->time_to_eat = ft_atoi(av[3]);
    info.data->time_to_sleep = ft_atoi(av[4]);
	info.data->nb_of_meals = -1;
    if(av[5] != NULL)
        info.data->nb_of_meals = ft_atoi(av[5]);
	if(init_mutex(&info))
		return(0);	

    printf("%d  %d  %d   %d  %d\n", info.data->nb_of_philo ,info.data->time_to_die ,info.data->time_to_eat ,
         info.data->time_to_sleep,info.data->nb_of_meals );
    
}