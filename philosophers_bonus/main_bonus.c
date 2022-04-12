/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:39:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/12 14:41:24 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int ac, char**av)
{
	t_all	info;
	t_data	data;

	info.data = &data;
	if (ac < 5 || ac > 6)
		return (put_err("Error\n", true));
	if (!parsing_arg(av))
		return (put_err("Error\n", true));
	info.data->nb_of_philo = ft_atoi(av[1]);
	info.data->time_to_die = ft_atoi(av[2]);
	info.data->time_to_eat = ft_atoi(av[3]);
	info.data->time_to_sleep = ft_atoi(av[4]);
	info.data->nb_of_meals = -1;
	if (av[5] != NULL)
		info.data->nb_of_meals = ft_atoi(av[5]);
	if (init_sems(&info))
		return (0);
	if (init_philo(&info))
		return (0);
	if (init_process(&info))
		return (0);
	free_all(&info);
}
