/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:17:23 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:59 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	message("kumpel mysli", philo, philo->id);
}

void	sleeping(t_philo *philo)
{
	int	tts;

	tts = (int *)philo->time_to_sleep;
	message("kumpel spie", philo, philo->id);
	usleep(tts * 1000);
}

void	eating(t_philo *philo)
{
	int	ttd;
	int	tte;

	ttd = (int *)philo->time_to_die;
	tte = (int *)philo->time_to_eat;
	pthread_mutex_lock(philo->r_fork);
	if (philo->philos == 1)
	{
		usleep(ttd * 1000);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	message("took fork", philo, philo->id);
	philo->eat = 1;
	message("eat", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(tte * 1000);
	pthreadd_mutex_unlock(philo->r_fork);
	pthreadd_mutex_unlock(philo->l_fork);
}
