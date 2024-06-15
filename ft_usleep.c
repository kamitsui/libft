/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:38:18 by kamitsui          #+#    #+#             */
/*   Updated: 2024/06/15 16:38:50 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

static int	check_time_enough(long long start_us, unsigned int micro_seconds)
{
	int				status;
	struct timeval	current;
	long long		current_us;
	long long		elapsed_us;

	status = gettimeofday(&current, NULL);
	if (status == -1)
		return (status);
	current_us = (current.tv_sec * 1000000LL) + current.tv_usec;
	elapsed_us = current_us - start_us;
	if (elapsed_us >= micro_seconds)
		return ((int)true);
	return ((int)false);
}

int	ft_usleep(unsigned int micro_seconds)
{
	int				status;
	struct timeval	start;
	long long		start_us;

	status = gettimeofday(&start, NULL);
	start_us = (start.tv_sec * 1000000LL) + start.tv_usec;
	while (true && status != -1)
	{
		status = check_time_enough(start_us, micro_seconds);
		if (status == true || status == -1)
			break ;
		status = usleep(100);
	}
	if (status == true)
		return (EXIT_SUCCESS);
	return (status);
}
