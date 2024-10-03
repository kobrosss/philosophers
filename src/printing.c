/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:36:53 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/03 17:14:28 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->time_start;
	if (!dead_lock(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
