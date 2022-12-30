/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:25:49 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 15:24:45 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	philo_populate(t_philo **philo, t_info *info)
{
	int	i;
	pthread_mutex_t *mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->nbr_philos);
	if (!philo)
		return (0);
	i = 0;
	//printf("nbr philos: %d", info->nbr_philos);
	while (i < info->nbr_philos)
	{
		(*philo)[i].nbr = i + 1;
		(*philo)[i].meal_counter = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].l_fork = philo[i]->nbr - 1;
		if ((*philo)[i].nbr == info->nbr_philos)
			(*philo)[i].r_fork = 0;
		else
			(*philo)[i].r_fork = philo[i]->nbr + 1;
		i++;
	}
	return (1);
}


int	philo_init(t_philo **philo, t_info *info)
{
	*philo = (t_philo *)malloc(sizeof(t_philo) * info->nbr_philos);
	if (!philo)
		return (0);
	if (!philo_populate(philo, info))
		return (0);
	return (1);
}
