/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:03:42 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/20 17:10:51 by andrferr         ###   ########.fr       */
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

void	*philo_life(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->nbr % 2 == 0)
		ft_usleep(philo->info->time_eat);
	while (!is_philo_dead(philo->info) && !enough_eat(philo))
	{
		if (!take_forks(philo))
			return (0);
		if (!is_philo_dead(philo->info) && !enough_eat(philo))
			eating(philo);
		if (!philo->info->philo_dead)
			thinking_msg(philo);
	}
	return (0);
}
