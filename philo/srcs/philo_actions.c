/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/06 11:19:53 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	if (is_philo_dead(philo->info))
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	eating_msg(philo);
	philo->last_meal = timestamp();
	philo->meal_counter++;
	ft_usleep(philo->info->time_eat);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (!is_philo_dead(philo->info))
		sleeping(philo);
}

void	sleeping(t_philo *philo)
{
	sleeping_msg(philo);
	ft_usleep(philo->info->time_sleep);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->dead);
	pthread_mutex_unlock(&philo->info->dead);
	if (is_philo_dead(philo->info) || enough_eat(philo))
		return (0);
	pthread_mutex_lock(&philo->l_fork);
	take_fork_msg(philo);
	if (philo->info->nbr_philos == 1)
	{
		ft_usleep(philo->info->time_die);
		pthread_mutex_unlock(&philo->l_fork);
		return (0);
	}
	pthread_mutex_lock(philo->r_fork);
	if (is_philo_dead(philo->info))
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	take_fork_msg(philo);
	return (1);
}
