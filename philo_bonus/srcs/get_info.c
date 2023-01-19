/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:08:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/19 14:46:42 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	assign_args(char **argv, t_info	**info)
{
	(*info)->philo_dead = 0;
	(*info)->nbr_philos = atoi(argv[1]);
	(*info)->time_die = atoi(argv[2]);
	(*info)->time_eat = atoi(argv[3]);
	(*info)->time_sleep = atoi(argv[4]);
	if (argv[5])
		(*info)->max_meals = atoi(argv[5]);
}

static int	check_to_return(char **argv, t_info *info)
{
	assign_args(argv, &info);
	if (argv[5] && atoi(argv[5]) == 0)
		return (0);
	if (info->time_eat == 0 || info->nbr_philos == 0)
		return (0);
	return (1);
}

t_info	*get_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	if (!check_to_return(argv, info))
	{
		free(info);
		return (0);
	}
	info->start = timestamp();
	info->philos = (int *)malloc(sizeof(int) * info->nbr_philos);
	if (!info->philos)
	{
		free(info);
		return (0);
	}
	return (info);
}
