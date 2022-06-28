/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:05:18 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/28 17:09:04 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    unsigned long	star_t;
    int				members;
    int				index;
    unsigned long	t_eat;
	unsigned long	t_sleep;
	unsigned long	t_die;
	unsigned long	l_t_eat;
	long long		n_of_eat;
	int				must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}       t_philo;
 // check_args
int	check_args(char **av);
int	check_int(char **av);
int help_args(char **av);

 // init_struct
t_philo	*init_struct(int ac, char **av, t_philo	*philo);
t_philo	*ft_init_forks(t_philo	*philo);
int	if_philo_finish_eating(t_philo *philo);

 // utils
int	ft_atoi(char *str);
unsigned long	get_time();
void	ft_usleep(unsigned long sleep);
# endif