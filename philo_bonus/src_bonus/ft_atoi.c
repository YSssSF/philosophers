/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:58:52 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 17:56:09 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

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

void	*ft_wait_for_eating(void *philos)
{
	t_philo_bonus	*philo;
	int				i;

	philo = (t_philo_bonus *)philos;
	i = 0;
	while (i < philo->members)
	{
		sem_wait(philo->sem->all_is_done);
		i++;
	}
	sem_post(philo->sem->done);
	exit(0);
}

void	ft_init_semaphor(t_philo_sem *philo_sem, int ph)
{
	sem_unlink("./forks");
	sem_unlink("./print");
	sem_unlink("./done");
	sem_unlink("./waiting");
	sem_unlink("./all_is_done");
	philo_sem->forks = sem_open("./forks", O_CREAT, 0777, ph);
	philo_sem->print = sem_open("./print", O_CREAT, 0777, 1);
	philo_sem->done = sem_open("./done", O_CREAT, 0777, 0);
	philo_sem->wait = sem_open("./waiting", O_CREAT, 0777, 1);
	philo_sem->all_is_done = sem_open("./all_is_done", O_CREAT, 0777, 0);
}

void	ft_start(t_philo_bonus *philo, int ph, int *philos_id, int ac)
{
	int	i;

	i = 0;
	while (i < ph)
	{
		philos_id[i] = fork();
		if (philos_id[i] == 0)
		{
			if (ac == 5)
				routine_1(&philo[i]);
			else if (ac == 6)
				routine_2(&philo[i]);
			exit (0);
		}
		i++;
	}
}
