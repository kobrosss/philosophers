/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:14:02 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/09 00:44:51 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "ERROR: gettimeofday()\n", 23);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t millisec)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < millisec)
		usleep(500);
	return (0);
}
