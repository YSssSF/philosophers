/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:33:57 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 17:11:29 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long sleep)
{
	long long	time;

	time = get_time();
	while (get_time() - time < sleep)
	{
		usleep (150);
	}
}

int	if_philo_finish_eating(t_philo_bonus *philo)
{
	int	i;

	i = 0;
	while (i < philo->members)
	{
		if (philo->n_of_eat != philo->must_eat)
			return (0);
		i++;
	}
	return (1);
}

t_philo_bonus	*init_struct(int ac, char **av, \
				t_philo_bonus *philo, t_philo_sem	*philo_sem)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].members = ft_atoi(av[1]);
		philo[i].index = i;
		philo[i].star_t = get_time();
		philo[i].t_die = ft_atoi(av[2]);
		philo[i].t_eat = ft_atoi(av[3]);
		philo[i].t_sleep = ft_atoi(av[4]);
		philo[i].must_eat = -1;
		philo[i].is_eating = 1;
		philo[i].n_of_eat = 0;
		philo[i].l_t_eat = get_time();
		philo[i].sem = philo_sem;
		if (ac == 6)
			philo[i].must_eat = ft_atoi(av[5]);
		i++;
	}
	return (philo);
}