/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 13:20:57 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
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
