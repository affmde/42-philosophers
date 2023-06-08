/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:19:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/03/14 13:29:47 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	atoi(const char *str)
{
	int				control;
	unsigned long	res;
	int				i;

	i = 0;
	res = 0;
	control = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		control = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > 9223372036854775807)
		{
			if (control > 0)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + (str[i++] - '0');
	}
	return ((int)res * control);
}

int	nbr_of_digits(long n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	return (1 + nbr_of_digits(n / 10));
}

unsigned long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(unsigned long t)
{
	unsigned long	time;

	time = timestamp();
	while (timestamp() - time < t)
		usleep(150);
}
