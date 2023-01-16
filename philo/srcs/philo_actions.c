/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:29 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 17:31:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	eating_msg(philo);
	philo->last_meal = timestamp();
	philo->meal_counter++;
	ft_usleep(philo->info->time_eat);
}

void	sleeping(t_philo *philo)
{
	sleeping_msg(philo);
	ft_usleep(philo->info->time_sleep);
}
