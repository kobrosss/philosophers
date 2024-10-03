/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:46:12 by rkobelie          #+#    #+#             */
/*   Updated: 2024/10/03 16:46:13 by rkobelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "src/initialization.c"
#include "utils/atoi.c"
#include "utils/get_time.c"
#include "utils/init_validation.c"

int	main(int ac, char **av)
{
	t_program program;
	t_philo philo[PHILO_LIMIT];
	pthread_mutex_t forks[PHILO_LIMIT];

	if (input_validation(av, ac))
	{
		init_program(philo, &program);
		init_input(&program, av);
		init_forks(forks, philo->philos);
		init_philos(&program, philo, forks, av);
	}
	else
	{
		printf("Initialization failed!\n");
		return (0);
	}


	printf("Initialization successful!\n");
	printf("Philosophers: %d\n", program.philos->philos);
	printf("Time to die: %zu\n", program.philos->time_to_die);
	printf("Time to eat: %zu\n", program.philos->time_to_eat);
	printf("Time to sleep: %zu\n", program.philos->time_to_sleep);
	printf("Times of eat: %d\n", program.philos->times_of_eat);
	return (0);


}