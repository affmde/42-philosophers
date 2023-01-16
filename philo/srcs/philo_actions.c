/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/14 10:33:31 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_eat_time(t_philo *philo)
{
	unsigned	int	last_time;
	unsigned	int time;
	unsigned int	final_time;
	
	if (philo->meal_counter)
		last_time = philo->last_meal;
	else
		last_time = philo->start;
	time = timestamp();
	final_time = time - last_time;
	if (final_time >= (unsigned int)philo->info->time_die)
		return (0);
	return (1);
}

int	eating(t_philo *philo)
{
	if (!check_eat_time(philo))
		return (0);
	eating_msg(philo);
	philo->meal_counter++;
	philo->last_meal = timestamp();
	usleep(philo->info->time_eat * 1000);
	return (1);
}

int	sleeping(t_philo *philo)
{
	sleeping_msg(philo);
	usleep(philo->info->time_sleep * 1000);
	return (1);
}
