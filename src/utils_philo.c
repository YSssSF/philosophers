/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:52:07 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/29 19:32:08 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_philo_is_eating_1(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->index]);
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d take a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(&philo->forks[(philo->index + 1) % philo->members]);
	philo->is_eating = 0;
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d take a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	printf("%llu		philo %d start eating \n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	philo->l_t_eat = get_time();
	ft_usleep(philo->t_eat);
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
}

void	ft_philo_is_eating_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->index]);
	pthread_mutex_lock(philo->print);
	printf("\033[0;32m %llu		philo %d take a fork \033[0m\n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(&philo->forks[(philo->index + 1) % philo->members]);
	pthread_mutex_lock(philo->print);
	printf("\033[0;33m %llu		philo %d take a fork \033[0m\n",
		(get_time() - philo->star_t), philo->index + 1);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	printf("\033[0;36m %llu		philo %d start eating \033[0m\n",
		(get_time() - philo->star_t), philo->index + 1);
	pthread_mutex_unlock(philo->print);
	philo->l_t_eat = get_time();
	ft_usleep(philo->t_eat);
	philo->n_of_eat++;
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->forks[philo->index]);
	pthread_mutex_unlock(&philo->forks[(philo->index + 1) % philo->members]);
}
