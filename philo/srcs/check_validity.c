/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:31:41 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:08 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_overflow(char *str)
{
	int	len;
	int	let;
	int	val;

	val = atoi(str);
	if (val < 0)
		len = nbr_of_digits(val) + 1;
	else
		len = nbr_of_digits(val);
	let = 0;
	while (str[let])
		let++;
	if (let != len)
		return (0);
	return (1);
}

int	check_argc_validity(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (!check_overflow(argv[i]))
			return (0);
		while (argv[i][++j])
			if (!check_isdigit(argv[i][j]))
				return (0);
	}
	return (1);
}
