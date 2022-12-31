/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/31 17:15:58 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead(t_philo *philo)
{
	if (timestamp() < philo->last_meal - philo->info->time_die)
}

void	*philo_life(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	printf("%d %ld\n", philo->nbr, philo->start);
	return (0);
}