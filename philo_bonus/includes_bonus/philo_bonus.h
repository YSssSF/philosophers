/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:02:12 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/07/04 16:26:58 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo_sem
{
	sem_t			*forks;
	sem_t			*print;
	sem_t			*done;
	sem_t			*wait;
	sem_t			*all_is_done;
}		t_philo_sem;

typedef struct s_philo_bonus
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
	int				*p_ids;
	t_philo_sem		*sem;
	int				must_eat;
}		t_philo_bonus;

// check_args

int				check_args(char **av);
int				check_int(char **av);
int				help_args(char **av);

// init_struct

t_philo_bonus	*init_struct(int ac, char **av, \
				t_philo_bonus *philo, t_philo_sem *philo_sem);
void			ft_philo_is_eating_1(t_philo_bonus *philo);
void			ft_philo_is_eating_2(t_philo_bonus *philo);

// utils

int				ft_atoi(char *str);
long long		get_time(void);
void			ft_usleep(long long sleep);
long long		get_time(void);
void			ft_usleep(long long sleep);
int				if_philo_finish_eating(t_philo_bonus *philo);
void			*ft_wait_for_eating(void *philos);
void			ft_init_semaphor(t_philo_sem *philo, int ph);
void			ft_start(t_philo_bonus *philo, int ph, int *philos_id, int ac);
void			routine_1(t_philo_bonus *philo);
void			routine_2(t_philo_bonus *philo);

#endif