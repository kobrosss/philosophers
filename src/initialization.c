/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:13:18 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/09 01:00:11 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_input(t_program *program, char **av)
{
	program->philos->philos = ft_atoi(av[1]);
	program->philos->time_to_die = (size_t)ft_atoi(av[2]);
	program->philos->time_to_eat = (size_t)ft_atoi(av[3]);
	program->philos->time_to_sleep = (size_t)ft_atoi(av[4]);
	program->philos->times_of_eat = -42;
	if (av[5])
		program->philos->times_of_eat = ft_atoi(av[5]);
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
		init_input(program, av);
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
	program->dead_flag = 0;
	program->philos = philo;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
