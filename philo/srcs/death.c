/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:55:58 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 13:28:09 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_philo_dead(t_info *info)
{
	if (info->philo_dead)
		return (1);
	return (0);
}

static int	check_dead(t_philo *philo)
{
	unsigned long	no_eat_time;
	unsigned long	time;

	time = timestamp();
	if (philo->meal_counter)
		no_eat_time = time - philo->last_meal;
	else
		no_eat_time = time - philo->info->start;
	if (no_eat_time > (unsigned long)philo->info->time_die)
	{
		printf("time: %lu\n", time);
		printf("start: %lu\n", philo->info->start);
		printf("meal counter: %d last meal: %lu\n", philo->meal_counter, philo->last_meal);
		printf("No time eat: %lu time_die: %lu\n", no_eat_time, (unsigned long)philo->info->time_die);
		philo->info->philo_dead = philo->nbr;
		philo->alive = 0;
		return (0);
	}
	return (1);
}

int	handle_death(t_info *info)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < info->nbr_philos)
		{
			if (info->nbr_times_eat && info->philos[i].meal_counter
				>= info->nbr_times_eat)
				return (0);
			if (!check_dead(&info->philos[i]))
			{
				dead_msg(&info->philos[i]);
				return (0);
			}
			i++;
		}
	}
	return (1);
}
