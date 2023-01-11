/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:25:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/11 16:58:09 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	wait_thread(t_info **info)
{
	int	i;

	i = -1;
	while (++i < (*info)->nbr_philos)
		if (pthread_join((*info)->philos[i].thread, NULL))
			return (0);
	return (1);
}

static int	philo_populate(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->nbr_philos)
	{
		info->philos[i].start = timestamp();
		info->philos[i].nbr = i + 1;
		info->philos[i].meal_counter = 0;
		info->philos[i].last_meal = 0;
		info->philos[i].alive = 1;
		if (pthread_mutex_init(&info->philos[i].l_fork, NULL))
			return (0);
		if (info->philos[i].nbr == info->nbr_philos)
			info->philos[i].r_fork = &info->philos[0].l_fork;
		else
			info->philos[i].r_fork = &info->philos[i + 1].l_fork;
		info->philos[i].info = info;
		if (pthread_create(&info->philos[i].thread, NULL,
				&philo_life, &info->philos[i]))
			return (0);
	}
	if (!wait_thread(&info))
		return (0);
	return (1);
}

int	philo_init(t_info *info)
{
	if (!philo_populate(info))
		return (0);
	return (1);
}
