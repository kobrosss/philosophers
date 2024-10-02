/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:52:27 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/02 22:32:27 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include "checking.c"

int dead_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if(*philo->dead = 1)
		return(pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return(0);
}

void	*philo_routine(void *pointer)
{
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	*observer;
	int			i;
	if(pthread_create(&observer, NULL, &monitoring, program->philos))
	{}
}

