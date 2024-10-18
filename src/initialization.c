/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:13:18 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/18 13:48:12 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_input(t_philo *philo, char **av)
{
	philo->philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->times_of_eat = ft_atoi(av[5]);
	else
		philo->times_of_eat = -42;
}

void	init_philos(t_program *program, t_philo *philo, pthread_mutex_t *forks,
		char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].eat = 0;
		philo[i].eaten = 0;
		init_input(&philo[i], av);
		philo[i].time_start = get_time();
		philo[i].last_meal = get_time();
		philo[i].write_lock = &program->write_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].dead = &program->dead_flag;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[philo[i].philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philos_quantity)
{
	int	i;

	i = 0;
	while (i < philos_quantity)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_philo *philo, t_program *program)
{
	write(1, "init 4\n", 7);
	program->dead_flag = 0;
	program->philos = philo;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
