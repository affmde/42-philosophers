/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:54:51 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/16 13:25:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork_msg(t_philo *philo)
{
	long long	time;

	if (!is_philo_dead(philo->info))
	{
		pthread_mutex_lock(&philo->info->message);
		time = timestamp() - philo->info->start;
		printf("%lld %d has taken a fork.\n", time, philo->nbr);
		pthread_mutex_unlock(&philo->info->message);
	}
}

void	eating_msg(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->message);
	time = timestamp() - philo->info->start;
	printf("%lld %d is eating.\n", time, philo->nbr);
	pthread_mutex_unlock(&philo->info->message);
}

void	sleeping_msg(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->message);
	time = timestamp() - philo->info->start;
	printf("%lld %d is sleeping.\n", time, philo->nbr);
	pthread_mutex_unlock(&philo->info->message);
}

void	thinking_msg(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->message);
	time = timestamp() - philo->info->start;
	printf("%lld %d is thinking.\n", time, philo->nbr);
	pthread_mutex_unlock(&philo->info->message);
}

void	dead_msg(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->info->message);
	time = timestamp() - philo->info->start;
	printf("%lld %d died.\n", time, philo->nbr);
	pthread_mutex_unlock(&philo->info->message);
}
