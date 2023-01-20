/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:49:14 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/20 17:09:08 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_info(t_info *info)
{
	int	i;

	i = 0;
	if (info)
	{
		pthread_mutex_destroy(&info->message);
		pthread_mutex_destroy(&info->dead);
		while (i < info->nbr_philos)
			pthread_mutex_destroy(&info->philos[i++].l_fork);
		if (info->philos)
			free(info->philos);
		if (info)
			free(info);
	}
}
