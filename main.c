/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:55:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:56 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
		return (1);
	if (!check_argc_validity(argv, argc))
		return (1);
	info = get_info(argv);
	if (info->nbr_philos == 1)
	{
		printf("%lld 1 died\n", timestamp());
		return (0);
	}
	if (!info)
		return (1);
	if (!philo_init(info))
		return (1);
	return (0);
}
