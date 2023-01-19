/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:43:37 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/19 17:49:01 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static t_philo	*philo_init(int num)
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->id = num + 1;
	philo->l_fork = 0;
	philo->r_fork = 0;
	philo->meals_counter = 0;
	philo->last_meal = timestamp();
	return (philo);
}

int	simulation(t_info *info)
{
	int	i;
	t_philo	*philo;
	
	i = 0;
	while (i < info->nbr_philos)
	{
		info->philos[i] = fork();
		if (info->philos[i] == 0)
			return (0);
		philo = philo_init(i);
		if (!philo)
			return (0);
		philo_life(info, philo);
		i++;
	}
	i = 0;
	while (i++ < info->nbr_philos)
		wait(NULL);
	return (0);
}
