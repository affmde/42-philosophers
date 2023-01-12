/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/12 11:58:20 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_other_philos_life(t_philo *philo);

static int	check_dead(t_philo *philo)
{
	long long	no_eat_time;
	long long	time;

	if (!check_other_philos_life(philo))
		return (0);
	time = timestamp();
	if (philo->meal_counter)
		no_eat_time = time - philo->last_meal;
	else
		no_eat_time = time - philo->start;
	if (no_eat_time > philo->info->time_die)
	{
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
	pthread_mutex_lock(philo->r_fork);
	take_fork_msg(philo);
	eating(philo);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (1);
}

static int	check_other_philos_life(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->nbr_philos)
	{
		if (philo->info->philos[i].alive == 0)
			return (0);
		i++;
	}
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
		if (philo->info->nbr_times_eat)
			if (philo->meal_counter >= philo->info->nbr_times_eat)
				return (0);
		if (!philo->alive)
			return (0);
		take_fork_and_eat(philo);
		sleeping(philo);
		thinking_msg(philo);
	}
	return (0);
}
