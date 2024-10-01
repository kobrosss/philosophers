/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:41:42 by rkobelie          #+#    #+#             */
/*   Updated: 2024/09/26 18:53:32 by rkobelie         ###   ########.fr       */
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
	return (1);
}
