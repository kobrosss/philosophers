/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:46:12 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/18 13:55:22 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	forks[PHILO_LIMIT];
	t_program		program;
	t_philo			philo[PHILO_LIMIT];

	if (input_validation(av, ac))
	{
		init_program(philo, &program);
		init_forks(forks, philo->philos);
		init_philos(&program, philo, forks, av);
		create_threads(&program, forks);
	}
	else
	{
		printf("Initialization failed!\n");
		return (0);
	}
}
