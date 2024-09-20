#include "../philo.h"

int	input_validation(char **av)
{
	if (av[1] > "200" && av[1] <= "0")
	{
		write(1, "ERROR: Invalide amount of philosophers", 38);
		return (0);
	}
}

/* int	init_(t_program program, char **av, int ac)
{
	if(input_validation(av) == 0)
		return(0);
	if (ac == 5 || ac == 6)
	{
		program.philos->philos = ft_atoi(av[1]);
		program.philos->time_to_die = (size_t)ft_atoi(av[2]);
		program.philos->time_to_eat = (size_t)ft_atoi(av[3]);
		program.philos->time_to_sleep = (size_t)ft_atoi(av[4]);
		program.philos->times_of_eat = 0;
		if (ac == 5)
			program.philos->times_of_eat = ft_atoi(av[5]);
	}
	return(0);
} */