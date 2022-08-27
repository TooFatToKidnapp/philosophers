/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:16:06 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/27 18:40:03 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

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
	info.data->flag = 0;
	if (av[5] != NULL)
		info.data->nb_of_meals = ft_atoi(av[5]);
	if (init_mutex(&info))
		return (free_and_destroy(&info), 1);
	if (init_philo(&info))
		return (free_and_destroy(&info), 1);
	if (thread(&info))
		return (free_and_destroy(&info), 1);
	return (0);
}
