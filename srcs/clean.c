/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:49:14 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/12 10:51:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_info(t_info *info)
{
	if (info)
	{
		if (info->philos)
			free(info->philos);
		if (info)
			free(info);
	}
}
