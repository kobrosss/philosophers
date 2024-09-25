/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:41:42 by rkobelie          #+#    #+#             */
/*   Updated: 2024/09/25 23:14:34 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	input_validation(char **av, int ac)
{
	int	j;

	j = 2;
	if (ac != 5 && ac != 6)
		return (0);
	if (ft_atoi(av[1]) > 200 && ft_atoi(av[1]) <= 0)
	{
		write(1, "ERROR: Invalide amount of philosophers\n", 40);
		return (0);
	}
	while (av[j])
	{
		if (ft_atoi(av[j]) <= 0)
		{
			write(1, "ERROR: Invalide time input\n", 28);
			return (0);
		}
		j++;
	}
}

int	init_input(t_program *program, char **av, int ac)
{
	if (input_validation(av, ac) == 0)
		return (0);
	program->philos->philos = ft_atoi(av[1]);
	program->philos->time_to_die = (size_t)ft_atoi(av[2]);
	program->philos->time_to_eat = (size_t)ft_atoi(av[3]);
	program->philos->time_to_sleep = (size_t)ft_atoi(av[4]);
	program->philos->times_of_eat = -42;
	if (av[5])
		program->philos->times_of_eat = ft_atoi(av[5]);
	return (1);
}

void	init_philos(t_program *program, t_philo *philo, pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].eat = 0;
		philo[i].eaten = 0;
		init_imput(&philo[i], av);
		philo[i].time_start = get_time();
		philo[i].last_meal = get_time();
		philo[i].write_lock = &program->write_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].dead = &program->dead_flag;
		philo[i].l_fork = &forks[i];
		if(i == 0)
			philo[i].r_fork = &forks[philo[i].philos - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void init_forks(pthread_mutex_t *forks, int philos_quantity)
{
	int i;

	i = 0;
	while(i < philos_quantity)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void init_program(t_philo *philo, t_program *program)
{
	program->dead_flag = 0;
	program->philos = philo;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
