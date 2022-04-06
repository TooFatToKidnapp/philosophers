/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:42:40 by aabdou            #+#    #+#             */
/*   Updated: 2022/04/04 02:28:19 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	put_err(char *str, bool i)
{
	printf("%s", str);
	if (i == true)
	{
		printf("Wrong use of the program!\nExpected arguments :"
			"    [number_of_philosophers]\n\t\t\t[time_to_die in ms]"
			"\n\t\t\t[time_to_eat in ms]\n\t\t\t[time_to_sleep in ms]\n\t\t\t"
			"[number_of_times_each_philosopher_must_eat] (optional)\n");
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	parsing_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]) || ft_atoi(av[i]) == -1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long	get_time(void)
{
	struct timeval	time;
	long			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (res);
}
