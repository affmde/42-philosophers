/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:04:19 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/19 17:45:43 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct s_info
{
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				philo_dead;
	int				*philos;
	unsigned long	start;
	sem_t			semaphore;
}	t_info;

typedef struct s_philo
{
	unsigned long	last_meal;
	int				r_fork;
	int				l_fork;
	int				meals_counter;
	int				id;
}	t_philo;

int				check_argc_validity(char **argv, int argc);
unsigned long	timestamp(void);
int				nbr_of_digits(long n);
t_info			*get_info(char **argv);
int				simulation(t_info *info);
int				philo_life(t_info *info, t_philo *philo);

#endif
