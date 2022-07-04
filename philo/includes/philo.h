/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:05:18 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 14:50:42 by yel-aoun         ###   ########.fr       */
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
	long long		star_t;
	int				members;
	int				index;
	long long		t_eat;
	long long		t_sleep;
	long long		t_die;
	long long		l_t_eat;
	int				is_eating;
	long long		n_of_eat;
	int				must_eat;
	pthread_mutex_t	*protect;
	pthread_mutex_t	*protect_nb_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
}		t_philo;

// check_args

int			check_args(char **av);
int			check_int(char **av);
int			help_args(char **av);

// init_struct

t_philo		*init_struct(int ac, char **av, t_philo	*philo);
t_philo		*ft_init_forks(t_philo	*philo);
void		ft_philo_is_eating_1(t_philo *philo);
void		ft_philo_is_eating_2(t_philo *philo);
int			if_philo_finish_eating(t_philo *philo);

// utils

int			ft_atoi(char *str);
long long	get_time(void);
void		ft_usleep(long long sleep);
void		ft_init(t_philo	*philo, pthread_mutex_t *init_forks, \
			pthread_mutex_t *init_printf, \
			pthread_mutex_t *protect_nb_eat);
#endif
