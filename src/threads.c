/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:52:27 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/09 21:25:31 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dead_lock(t_philo *philo)
{
	printf("dead_lock\n");
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	printf("routine\n");
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if(philo->id % 2 == 0)
		ft_usleep(1);
	while (dead_lock(philo) != 1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (pointer);
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	printf("threads\n ");
	pthread_t	observer;
	int			i;

	i = 0;
	if (pthread_create(&observer, NULL, &monitoring, program->philos) != 0)
		exit_kill(program, forks);
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
