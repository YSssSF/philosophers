/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:37:41 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/28 17:34:56 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

unsigned long	get_time()
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(unsigned long sleep)
{
	unsigned long	time;

	time = get_time();
	while (get_time() - time < sleep)
	{
		usleep (500);
	}
}

int	if_philo_finish_eating(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->members)
	{
		if (philo[i].n_of_eat != philo->must_eat)
			return(0);
		i++;
	}
	return (1);
}

t_philo	*ft_init_forks(t_philo	*philo)
{
	pthread_mutex_t *init_forks;
	pthread_mutex_t *init_printf;
	int	i;

	init_forks = malloc(sizeof(pthread_mutex_t) * philo->members);
	init_printf = malloc(sizeof(pthread_mutex_t));
	if (!init_forks || !init_printf)
		return (0);
	pthread_mutex_init(init_printf, NULL);
	i = 0;
	while (i < philo->members)
	{
		pthread_mutex_init(&init_forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo->members)
	{
		philo[i].forks = init_forks;
		philo[i].print = init_printf;
		i++;
	}
	return (philo);
}

t_philo	*init_struct(int ac, char **av, t_philo	*philo)
{
	int	i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		philo[i].members = ft_atoi(av[1]);
		philo[i].index = i;
		philo[i].star_t = get_time();
		philo[i].t_die = ft_atoi(av[2]);
		philo[i].t_eat = ft_atoi(av[3]);
		philo[i].t_sleep = ft_atoi(av[4]);
		philo[i].must_eat = -1;
		philo[i].n_of_eat = 0;
		philo[i].l_t_eat = 0;
		if (ac == 6)
			philo[i].must_eat = ft_atoi(av[5]);
		i++;
	}
	return (philo);
}