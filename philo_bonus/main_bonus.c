/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:39:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/13 13:11:35 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_all	all;
	t_data	data;

	all.data = &data;
	if ((argc < 5 || argc > 6))
		return (put_err("Arguments error\n", 1));
	if (!parsing_arg(argv))
		return (put_err("Arguments error\n", 1));
	all.data->nb_of_philo = ft_atoi(argv[1]);
	all.data->time_to_die = ft_atoi(argv[2]);
	all.data->time_to_eat = ft_atoi(argv[3]);
	all.data->time_to_sleep = ft_atoi(argv[4]);
	all.data->nb_of_meals = -1;
	if (argc > 5)
		all.data->nb_of_meals = ft_atoi(argv[5]);
	if (init_sems(&all))
		return (0);
	if (init_philo(&all))
		return (0);
	if (init_process(&all))
		return (0);
	free_all(&all);
}
