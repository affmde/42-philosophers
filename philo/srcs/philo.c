/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/13 17:21:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_dead(t_philo *philo)
{
	unsigned long	no_eat_time;
	unsigned long	time;

	if (philo->info->philo_dead)
		return (0);
	time = timestamp();
	if (philo->meal_counter)
		no_eat_time = time - philo->last_meal;
	else
		no_eat_time = time - philo->start;
	if (no_eat_time >= (unsigned long)philo->info->time_die)
	{
		philo->info->philo_dead = 1;
		philo->alive = 0;
		dead_msg(philo);
		return (0);
	}
	return (1);
}

static int	take_fork_and_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	take_fork_msg(philo);
	if (philo->info->nbr_philos == 1)
	{
		usleep((philo->info->time_die) * 1000);
		pthread_mutex_unlock(&philo->l_fork);
		return (0);
	}
	pthread_mutex_lock(philo->r_fork);
	if (philo->info->philo_dead)
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	take_fork_msg(philo);
	eating(philo);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (1);
}

void	*philo_life(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->nbr % 2 == 0)
		usleep(philo->info->time_eat * 1000);
	while (check_dead(philo))
	{
		if (!take_fork_and_eat(philo) && !philo->info->philo_dead)
			continue ;
		if (philo->info->nbr_philos > 1 && !philo->info->philo_dead)
			sleeping(philo);
		if (philo->info->nbr_philos > 1 && !philo->info->philo_dead)
			thinking_msg(philo);
		if (philo->info->nbr_times_eat)
			if (philo->meal_counter >= philo->info->nbr_times_eat)
				return (0);
	}
	return (0);
}
