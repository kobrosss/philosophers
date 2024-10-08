/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:33:53 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/08 21:47:24 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	exit_kill(t_program *program, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	write(1, "ERROR : problem with threads/mutexes\n", 38);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	while (i < program[0].philos->philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}