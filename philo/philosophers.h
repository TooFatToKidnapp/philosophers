/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:11:26 by aabdou            #+#    #+#             */
/*   Updated: 2022/03/27 19:44:58 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct mutex
{
    pthread_mutex_t *forks;
    pthread_mutex_t *output;
} t_mutex;

typedef struct data
{
    int nb_of_philo;
	int time_to_die;
	int time_to_eat;	
	int time_to_sleep;
	int nb_of_meals;
	t_mutex fork;
}   t_data;

typedef struct philo
{
    int	philo_id;
	int eat_count;
	long start_time;
	long last_meal;
	t_data *args;
	t_mutex *mutex;
	pthread_t thread;
	pthread_mutex_t right_fork;
	pthread_mutex_t left_fork;
}	t_philo;

typedef struct all
{
	pthread_t death;
	t_mutex *lock;
	t_philo *philo;
	t_data	*data;
}	t_all;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int put_err(char *str, bool i);
int parsing_arg(char **av);
int init_mutex(t_all *info);

#endif