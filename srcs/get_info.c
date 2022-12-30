/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:08:18 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 14:08:19 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_info(t_info *info, char **argv)
{
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->nbr_philos = atoi(argv[1]);
	info->time_die = atoi(argv[2]);
	info->time_eat = atoi(argv[3]);
	info->time_sleep = atoi(argv[4]);
	if (argv[5])
		info->nbr_times_eat = atoi(argv[5]);
	if (info->time_eat == 0)
		return (0);
	return (1);
}
