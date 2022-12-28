/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:55:52 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/28 17:24:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*send_message(void *ptr)
{
	ptr = NULL;
	printf("This is my message\n");
	sleep(3);
	printf("This is my second message\n");
	return (NULL);
}

int	main(void)
{
	pthread_t t1;
	char *str = "Hello";
	pthread_create(&t1, NULL, send_message, str);
	pthread_join(t1, NULL);
	return (0);
}
