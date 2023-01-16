/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 17:32:02 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	enough_eat(t_philo *philo)
{
	if (philo->info->nbr_times_eat)
	{
		if (philo->meal_counter >= philo->info->nbr_times_eat)
			return (1);
	}
	return (0);
}

static int	take_fork_and_eat(t_philo *philo)
{
	if (is_philo_dead(philo->info) || enough_eat(philo))
		return (0);
	pthread_mutex_lock(&philo->l_fork);
	take_fork_msg(philo);
	if (philo->info->nbr_philos == 1)
	{
		ft_usleep((philo->info->time_die));
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
		ft_usleep(philo->info->time_eat);
	while (!is_philo_dead(philo->info) || !enough_eat(philo))
	{
		if (philo->info->nbr_philos > 1 && !philo->info->philo_dead
			&& philo->meal_counter)
			thinking_msg(philo);
		if (!take_fork_and_eat(philo))
			return (0);
		if (philo->info->nbr_philos > 1 && !philo->info->philo_dead)
			sleeping(philo);
		if (!enough_eat(philo) && !philo->info->philo_dead)
			thinking_msg(philo);
	}
	return (0);
}
