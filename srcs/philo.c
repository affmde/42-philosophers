/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/10 17:50:45 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_dead(t_philo *philo)
{
	long long no_eat_time;
	long long	time;

	time = timestamp();

	if (philo->meal_counter)
		no_eat_time = time - philo->last_meal;
	else
		no_eat_time = time - philo->start;
	if (no_eat_time > philo->info->time_die)
	{
		dead_msg(philo);
		return (0);
	}
	return (1);
}

static int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	take_fork_msg(philo);
	eating(philo);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);

	return (1);
}

void	*philo_life(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	while (check_dead(philo))
	{
		take_fork(philo);
		sleeping(philo);
		thinking_msg(philo);
	}
	return (0);
}
