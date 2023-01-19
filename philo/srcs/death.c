/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:55:58 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/19 13:46:33 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_philo_dead(t_info *info)
{
	pthread_mutex_lock(&info->dead);
	if (info->philo_dead)
	{
		pthread_mutex_unlock(&info->dead);
		return (1);
	}
	pthread_mutex_unlock(&info->dead);
	return (0);
}

static int	check_dead(t_philo *philo)
{
	unsigned long	no_eat_time;
	unsigned long	time;

	pthread_mutex_lock(&philo->info->dead);
	time = timestamp();
	if (philo->meal_counter)
		no_eat_time = time - philo->last_meal;
	else
		no_eat_time = time - philo->info->start;
	if (no_eat_time >= (unsigned long)philo->info->time_die)
	{
		philo->info->philo_dead = philo->nbr;
		pthread_mutex_unlock(&philo->info->dead);
		return (0);
	}
	pthread_mutex_unlock(&philo->info->dead);
	return (1);
}

int	handle_death(t_info *info)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < info->nbr_philos)
		{
			if (!check_dead(&info->philos[i]))
			{
				usleep(100);
				dead_msg(&info->philos[i]);
				return (0);
			}
			if (enough_eat(&info->philos[i]))
				return (0);
		}
	}
	return (1);
}
