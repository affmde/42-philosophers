/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:56:41 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 14:06:00 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_info
{
	int	nbr_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nbr_times_eat;

}	t_info;

typedef struct s_philo
{
	int				nbr;
	int				meal_counter;
	int				last_meal;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	*mutex;
	t_info			info;

}	t_philo;

int	get_info(t_info *info, char **argv);
int	atoi(const char *str);
int	check_argc_validity(char **argv, int argc);
int	check_isdigit(int num);
int	nbr_of_digits(long n);
int	philo_init(t_philo **philo, t_info *info);

#endif
