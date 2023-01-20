/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:56:41 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/20 17:06:48 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>

typedef struct s_philo
{
	int					nbr;
	int					meal_counter;
	unsigned long		last_meal;
	pthread_t			thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		l_fork;
	struct s_info		*info;
}	t_philo;

typedef struct s_info
{
	t_philo				*philos;
	int					nbr_philos;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nbr_times_eat;
	int					philo_dead;
	unsigned long		start;
	pthread_mutex_t		message;
	pthread_mutex_t		dead;
}	t_info;

t_info			*get_info(char **argv);
int				atoi(const char *str);
int				check_argc_validity(char **argv, int argc);
int				nbr_of_digits(long n);
int				philo_init(t_info *info);
void			*philo_life(void *p);
unsigned long	timestamp(void);
void			take_fork_msg(t_philo *philo);
void			eating_msg(t_philo *philo);
void			sleeping_msg(t_philo *philo);
void			thinking_msg(t_philo *philo);
void			dead_msg(t_philo *philo);
int				take_forks(t_philo *philo);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			clean_info(t_info *info);
int				wait_thread(t_info **info);
int				is_philo_dead(t_info *info);
int				handle_death(t_info *info);
int				enough_eat(t_philo *philo);
void			ft_usleep(unsigned long t);

#endif
