/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:16:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/26 22:28:22 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int main(int ac, char**av)
{
    t_philo data;
    
    if(ac < 5 || ac > 6)
        return(put_err("Error\n", true));
    if(!parsing_arg(av))
        return(put_err("Error\n", true));
    data.nb_of_philo = ft_atoi(av[1]);
    data.time_to_die = ft_atoi(av[2]);
    data.time_to_eat = ft_atoi(av[3]);
    data.time_to_sleep = ft_atoi(av[4]);
    if(av[5] != NULL)
        data.nb_of_meals = ft_atoi(av[5]);

   printf("%d  %d  %d   %d  %d\n", data.nb_of_philo ,data.time_to_die ,data.time_to_eat ,
         data.time_to_sleep,data.nb_of_meals );
    
}