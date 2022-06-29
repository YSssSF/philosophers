/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:05:28 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/29 19:39:54 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	check_die(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->members && !if_philo_finish_eating(philo))
	{
		if ((get_time() - philo[i].l_t_eat) >= philo->t_die
			&& philo[i].is_eating == 1)
		{
			pthread_mutex_lock(philo->print);
			printf("%llu philo number %d die\n",
				(get_time() - philo->star_t), (philo[i].index + 1));
			pthread_mutex_destroy(philo->forks);
			pthread_mutex_destroy(philo->print);
			return ;
		}
		i = (i + 1) % philo->members;
	}
}

void	*routine_2(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (philo->n_of_eat < philo->must_eat)
	{
		ft_philo_is_eating_2(philo);
		pthread_mutex_lock(philo->print);
		printf("%llu ms: philo %d is sleeping\n",
			(get_time() - philo->star_t), philo->index + 1);
		pthread_mutex_unlock(philo->print);
		ft_usleep(philo->t_sleep);
		pthread_mutex_lock(philo->print);
		printf("%llu ms: philo %d is thinking\n",
			(get_time() - philo->star_t), philo->index + 1);
		pthread_mutex_unlock(philo->print);
	}
	return (0);
}

void	*routine_1(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (1)
	{
		ft_philo_is_eating_1(philo);
		pthread_mutex_lock(philo->print);
		printf("%llu ms: philo %d is sleeping\n",
			(get_time() - philo->star_t), philo->index + 1);
		pthread_mutex_unlock(philo->print);
		ft_usleep(philo->t_sleep);
		pthread_mutex_lock(philo->print);
		printf("%llu ms: philo %d is thinking\n",
			(get_time() - philo->star_t), philo->index + 1);
		pthread_mutex_unlock(philo->print);
	}
}

void	ft_creat_philosofers(int ac, char **av, int ph)
{
	t_philo		*philo;
	pthread_t	*n_philo;
	int			i;

	philo = malloc(sizeof(t_philo) * ph);
	n_philo = malloc(sizeof(pthread_t) * ph);
	if (!n_philo || !philo)
		return ;
	philo = init_struct(ac, av, philo);
	philo = ft_init_forks(philo);
	i = 0;
	while (i < ph)
	{
		philo[i].l_t_eat = get_time();
		if (ac == 5)
			pthread_create(&n_philo[i], NULL, &routine_1, &philo[i]);
		else if (ac == 6)
			pthread_create(&n_philo[i], NULL, &routine_2, &philo[i]);
		i++;
		usleep(100);
	}
	check_die(philo);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (help_args(av) && check_int(av))
			ft_creat_philosofers(ac, av, ft_atoi(av[1]));
		else
			printf("Error : invalide argument's\n");
	}
	else if (ac < 5)
		printf("Error : Need mor argument's\n");
	else
		printf("Error : Too mutch argumrnt's\n");
	return (0);
}
