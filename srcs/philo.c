/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/04 16:27:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_dead(t_philo *philo)
{
	long long no_eat_time;

	if (!philo->alive)
	{
		printf("DEAD!!!!!!!!!");
		return (0);
	}
	if (philo->meal_counter)
		no_eat_time = timestamp() - philo->last_meal;
	else
		no_eat_time = timestamp() - philo->start;
	if (no_eat_time > philo->info->time_die)
		return (0);
	return (1);
}

static int	take_fork(t_philo *philo)
{
	philo = NULL;
	return (1);
}

void	*philo_life(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	while (!check_dead(philo))
	{
		take_fork(philo);
	}

	return (0);
}
