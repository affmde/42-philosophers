/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:10:57 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/19 17:48:12 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	philo_life(t_info *info, t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(info->time_eat);
	while (!info->philo_dead)
	{
		printf("philo nbr %d is here\n", philo->id);
	}
	return (0);
}
