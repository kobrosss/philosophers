#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_LIMIT 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat;
	int				eaten;
	int				philos;
	int				*dead;
	int				times_of_eat;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_start;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

void				init_philos(t_program *program, t_philo *philo,
						pthread_mutex_t *forks, char **av);
void				message(char *str, t_philo *philo, int id);
void				*philo_routine(void *pointer);
int					check_dead(t_philo *philo, size_t time_to_die);
int					if_philo_dead(t_philo *philo);
int					if_all_ate(t_philo *philo);
void				*monitoring(void *pointer);
int					ft_atoi(char *nptr);
int					input_validation(char **av, int ac);
size_t				get_time(void);
void				init_input(t_program *program, char **av);
void				init_program(t_philo *philo, t_program *program);
int					dead_lock(t_philo *philo);

#endif