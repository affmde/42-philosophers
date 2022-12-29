/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:55:52 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/29 14:38:21 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*send_email(void *ptr)
{
	int	i;
	int	*email;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

	email = ptr;
	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		*email += 1;
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}

int	main(void)
{
	pthread_t t1;
	pthread_t t2;
	int	email = 0;
	pthread_create(&t1, NULL, &send_email, &email);
	pthread_create(&t2, NULL, &send_email, &email);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("email: %d\n", email);
	return (0);
}
