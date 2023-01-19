/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:01:43 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/19 17:33:30 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info *info;

	if (argc != 5 && argc != 6)
		return (1);
	if (!check_argc_validity(argv, argc))
		return (1);
	info = get_info(argv);
	sem_open((char *)&info->semaphore, 1, info->nbr_philos);
	simulation(info);
	sem_close(&info->semaphore);
	return (0);
}
