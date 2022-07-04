/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:52:07 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 15:14:30 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_is_eating_1(t_philo *philo)
{
	pthread_mutex_lock(philo->protect);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->protect);
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d has taken a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d is eating \n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->protect);
	philo->l_t_eat = get_time();
	pthread_mutex_unlock(philo->protect);
	ft_usleep(philo->t_eat);
	pthread_mutex_lock(philo->protect);
	philo->is_eating = 1;
	pthread_mutex_unlock(philo->protect);
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
}

void	ft_philo_is_eating_2(t_philo *philo)
{
	pthread_mutex_lock(philo->protect);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->protect);
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d  has taken a fork\n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d is eating\n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->protect);
	philo->l_t_eat = get_time();
	pthread_mutex_unlock(philo->protect);
	ft_usleep(philo->t_eat);
	pthread_mutex_lock(philo->protect_nb_eat);
	philo->n_of_eat++;
	pthread_mutex_unlock(philo->protect_nb_eat);
	pthread_mutex_lock(philo->protect);
	philo->is_eating = 1;
	pthread_mutex_unlock(philo->protect);
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
}
