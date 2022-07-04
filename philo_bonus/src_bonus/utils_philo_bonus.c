/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:01:35 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 17:40:19 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philo_bonus.h"

void	ft_philo_is_eating_1(t_philo_bonus *philo)
{
	sem_wait(philo->sem->forks);
	sem_wait(philo->sem->print);
	printf("%llu		philo %d  has taken a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	sem_post(philo->sem->print);
	sem_wait(philo->sem->forks);
	philo->is_eating = 0;
	sem_wait(philo->sem->print);
	printf("%llu		philo %d  has taken a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	sem_post(philo->sem->print);
	sem_wait(philo->sem->print);
	printf("%llu		philo %d is eating \n",
		(get_time() - philo->star_t), philo->index + 1);
	sem_post(philo->sem->print);
	philo->l_t_eat = get_time();
	ft_usleep(philo->t_eat);
	philo->is_eating = 1;
	sem_post(philo->sem->forks);
	sem_post(philo->sem->forks);
}

void	ft_philo_is_eating_2(t_philo_bonus *philo)
{
	sem_wait(philo->sem->forks);
	sem_wait(philo->sem->print);
	printf("%llu		philo %d  has taken a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	sem_post(philo->sem->print);
	sem_wait(philo->sem->forks);
	philo->is_eating = 0;
	sem_wait(philo->sem->print);
	printf("%llu		philo %d  has taken a fork \n",
		(get_time() - philo->star_t), philo->index + 1);
	sem_post(philo->sem->print);
	sem_wait(philo->sem->print);
	printf("%llu		philo %d is eating \n",
		(get_time() - philo->star_t), philo->index + 1);
	sem_post(philo->sem->print);
	philo->l_t_eat = get_time();
	ft_usleep(philo->t_eat);
	philo->n_of_eat++;
	if (philo->n_of_eat >= philo->must_eat)
		sem_post(philo->sem->all_is_done);
	philo->is_eating = 1;
	sem_post(philo->sem->forks);
	sem_post(philo->sem->forks);
}
