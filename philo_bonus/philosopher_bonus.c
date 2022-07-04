/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:58:02 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 17:57:33 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/philo_bonus.h"

void	*check_die(void *philos)
{
	t_philo_bonus	*philo;

	philo = (t_philo_bonus *)philos;
	while (1)
	{
		sem_wait(philo->sem->wait);
		if ((get_time() - philo->l_t_eat) >= philo->t_die
			&& philo->is_eating == 1)
		{
			sem_wait(philo->sem->print);
			printf("\033[0;31m%llu		philo number %d died \033[0m\n",
				(get_time() - philo->star_t), (philo->index + 1));
			sem_post(philo->sem->done);
			break ;
		}
		sem_post(philo->sem->wait);
		usleep(20);
	}
	return (0);
}

void	routine_1(t_philo_bonus *philo)
{
	pthread_t	check_death;

	pthread_create(&check_death, NULL, &check_die, philo);
	while (1)
	{
		ft_philo_is_eating_1(philo);
		sem_wait(philo->sem->print);
		printf("%llu		philo %d is sleeping\n",
			(get_time() - philo->star_t), philo->index + 1);
		sem_post(philo->sem->print);
		ft_usleep(philo->t_sleep);
		sem_wait(philo->sem->print);
		printf("%llu		philo %d is thinking\n",
			(get_time() - philo->star_t), philo->index + 1);
		sem_post(philo->sem->print);
	}
}

void	routine_2(t_philo_bonus *philo)
{
	pthread_t	check_death;

	pthread_create(&check_death, NULL, &check_die, philo);
	while (philo->n_of_eat < philo->must_eat)
	{
		ft_philo_is_eating_2(philo);
		sem_wait(philo->sem->print);
		printf("%llu		philo %d is sleeping\n",
			(get_time() - philo->star_t), philo->index + 1);
		sem_post(philo->sem->print);
		ft_usleep(philo->t_sleep);
		sem_wait(philo->sem->print);
		printf("%llu		philo %d is thinking\n",
			(get_time() - philo->star_t), philo->index + 1);
		sem_post(philo->sem->print);
	}
}

void	ft_creat_philosofers(int ac, char **av, int ph)
{
	t_philo_bonus	*philo;
	t_philo_sem		*philo_sem;
	pthread_t		f_eating;
	int				*philos_id;
	int				i;

	philo_sem = malloc(sizeof(t_philo_sem));
	philo = malloc(sizeof(t_philo_bonus) * ph);
	philos_id = malloc(sizeof(int) * ph);
	if (!philo || !philos_id || !philo_sem)
		return ;
	ft_init_semaphor(philo_sem, ph);
	philo = init_struct(ac, av, philo, philo_sem);
	ft_start(philo, ph, philos_id, ac);
	pthread_create(&f_eating, NULL, &ft_wait_for_eating, philo);
	sem_wait(philo->sem->done);
	i = 0;
	while (i < ph)
	{
		kill(philos_id[i], SIGKILL);
		i++;
	}
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
