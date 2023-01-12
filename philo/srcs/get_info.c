/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:08:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/12 14:22:18 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_info	*get_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	if (pthread_mutex_init(&info->message, NULL))
		return (0);
	if (pthread_mutex_init(&info->dead, NULL))
		return (0);
	info->philo_dead = 0;
	info->nbr_philos = atoi(argv[1]);
	info->time_die = atoi(argv[2]);
	info->time_eat = atoi(argv[3]);
	info->time_sleep = atoi(argv[4]);
	if (argv[5])
		info->nbr_times_eat = atoi(argv[5]);
	if (info->time_eat == 0)
	{
		free(info);
		return (0);
	}
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->nbr_philos);
	if (!info->philos)
		return (0);
	return (info);
}