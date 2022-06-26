/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:05:53 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/20 20:16:25 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] <= 32)
			j++;
		while(av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] <= 32)
			j++;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (j > 0)
			if ((av[i][j - 1] == '-' && av[i][j] == '\0')
				|| ((av[i][j - 1] == '+' && av[i][j] == '\0')))
				return (0);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int help_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (check_args(av));
}
