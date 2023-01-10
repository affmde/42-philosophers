/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:56:41 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/10 17:17:09 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				nbr;
	int				meal_counter;
	int				alive;
	long int		last_meal;
	long int		start;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	struct s_info			*info;
}	t_philo;

typedef struct s_info
{
	int	nbr_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nbr_times_eat;
	t_philo *philos;
}	t_info;

t_info	*get_info(char **argv);
int		atoi(const char *str);
int		check_argc_validity(char **argv, int argc);
int		check_isdigit(int num);
int		nbr_of_digits(long n);
int		philo_init(t_info *info);
void	*philo_life(void *p);
void	go_sleep(int t);
long long	timestamp(void);
void	take_fork_msg(t_philo *philo);
void	eating_msg(t_philo *philo);
void	sleeping_msg(t_philo *philo);
void	thinking_msg(t_philo *philo);
void	dead_msg(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

#endif
