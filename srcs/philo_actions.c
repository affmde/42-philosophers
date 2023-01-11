/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/11 14:34:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	eating_msg(philo);
	philo->meal_counter++;
	philo->last_meal = timestamp();
	usleep(philo->info->time_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	sleeping_msg(philo);
	usleep(philo->info->time_sleep * 1000);
}
