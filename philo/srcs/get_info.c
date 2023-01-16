/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:08:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 18:09:27 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	set_philos_to_zero(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philos)
	{
		memset(&info->philos[i], 0, sizeof(info->philos[i]));
		i++;
	}
}

static void	assign_args(char **argv, t_info	**info)
{
	(*info)->philo_dead = 0;
	(*info)->nbr_philos = atoi(argv[1]);
	(*info)->time_die = atoi(argv[2]);
	(*info)->time_eat = atoi(argv[3]);
	(*info)->time_sleep = atoi(argv[4]);
	if (argv[5])
		(*info)->nbr_times_eat = atoi(argv[5]);
}

static int	check_to_return(char **argv, t_info *info)
{
	if (pthread_mutex_init(&info->message, NULL))
		return (0);
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
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->nbr_philos);
	if (!info->philos)
		return (0);
	set_philos_to_zero(info);
	info->start = timestamp();
	return (info);
}
