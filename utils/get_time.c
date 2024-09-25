#include "../philo.h"

size_t	get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "ERROR: gettimeofday()\n", 23);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}