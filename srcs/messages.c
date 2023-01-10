/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:54:51 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/10 17:03:52 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork_msg(t_philo *philo)
{
	long long	time;

	time = timestamp();
	printf("%lld %d has taken a fork.\n", time, philo->nbr);
}

void	eating_msg(t_philo *philo)
{
	long long	time;

	time = timestamp();
	printf("%lld %d is eating.\n", time, philo->nbr);
}

void	sleeping_msg(t_philo *philo)
{
	long long	time;

	time = timestamp();
	printf("%lld %d is sleeping.\n", time, philo->nbr);
}

void	thinking_msg(t_philo *philo)
{
	long long	time;

	time = timestamp();
	printf("%lld %d is thinking.\n", time, philo->nbr);
}

void	dead_msg(t_philo *philo)
{
	long long	time;

	time = timestamp();
	printf("%lld %d died.\n", time, philo->nbr);
}
