/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:52:27 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/21 19:30:53 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dead_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(350);
	while (!dead_lock(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (pointer);
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitoring, program->philos) != 0)
		exit_kill(program, forks);
	i = 0;
	while (i < program->philos[0].philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			exit_kill(program, forks);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		exit_kill(program, forks);
	i = 0;
	while (i < program->philos[0].philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			exit_kill(program, forks);
		i++;
	}
	return (0);
}
