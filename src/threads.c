/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:52:27 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/08 21:45:07 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include "checking.c"

int	dead_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead = 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (!dead_lock(philo))
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (pointer);
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	*observer;
	int			i;

	i = 0;
	if (pthread_create(&observer, NULL, &monitoring, program->philos) != 0)
		exit_kill(program, forks);
	while (i < program[0].philos->philos)
	{
		if (pthread_create(&program[i].philos->thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			exit_kill(program, forks);
		i++;
	}
	i = 0;
	if(pthread_join(observer, NULL) != 0)
		exit_kill(program, forks);
	while(i < program[0].philos->philos)
	{
		if(pthread_join(program->philos[i].thread, NULL) != 0)
			exit_kill(program, forks);
		i++;
	}
	return(0);
}
