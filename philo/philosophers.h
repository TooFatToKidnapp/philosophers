/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:11:26 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/26 22:18:40 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct lock
{
    pthread_mutex_t *forks;
} t_lock;

typedef struct args
{
    int nb_of_philo;
	int time_to_die;
	int time_to_eat;	
	int time_to_sleep;
	int nb_of_meals;
	t_lock fork;
}   t_philo;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int put_err(char *str, bool i);
int parsing_arg(char **av);

#endif