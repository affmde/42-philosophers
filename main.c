/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:55:52 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 14:08:50 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_info *info;
	t_philo *philo;

	info = NULL;
	philo = NULL;
	if (argc != 5 && argc != 6)
		return (1);
	if (!check_argc_validity(argv, argc))
		return (1);
	if (!get_info(info, argv))
		return (1);
	if (!philo_init(&philo, info))
		return (1);
	return (0);
}
