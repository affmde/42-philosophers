/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:55:52 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 13:26:36 by andrferr         ###   ########.fr       */
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
	if (!info)
		return (1);
	philo_init(info);

	/*--------------------------------------------------------------------------*/
	//Check how many times every philo ate
	for (int i = 0; i < info->nbr_philos; i++)
		printf("Philo %d ate %d times. alive status: %d\n", i + 1, info->philos[i].meal_counter, info->philos[i].alive);
	clean_info(info);
	printf("progrm finished at: %lu\n", timestamp() - info->start);
	/*--------------------------------------------------------------------------*/

	return (0);
}
