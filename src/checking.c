/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:35:38 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/03 17:15:14 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= time_to_die && philo->eat == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	if_philo_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philos)
	{
		if (check_dead(&philo[i], philo[i].time_to_die))
		{
			message("dead", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	if_all_ate(t_philo *philo)
{
	int	i;
	int	ate;

	i = 0;
	ate = 0;
	if (philo[0].times_of_eat == -42)
		return (0);
	while (i < philo[0].philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].eaten >= philo[i].times_of_eat)
			ate++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (ate == philo[0].times_of_eat)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (if_all_ate == 1 || if_philo_dead == 1)
			break ;
	}
	return (pointer);
}
