/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:37:37 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 14:51:19 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sin;
	int	result;

	i = 0;
	sin = 1;
	result = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin *= (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sin);
}

void	ft_init(t_philo	*philo, pthread_mutex_t *init_forks, \
		pthread_mutex_t *init_printf, pthread_mutex_t *protect_nb_eat)
{
	int	i;

	pthread_mutex_init(init_printf, NULL);
	pthread_mutex_init(protect_nb_eat, NULL);
	i = 0;
	while (i < philo->members)
	{
		pthread_mutex_init(&init_forks[i], NULL);
		philo[i].protect = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i].protect, NULL);
		i++;
	}
	i = 0;
	while (i < philo->members)
	{
		philo[i].forks = init_forks;
		philo[i].print = init_printf;
		philo[i].protect_nb_eat = protect_nb_eat;
		i++;
	}
}
