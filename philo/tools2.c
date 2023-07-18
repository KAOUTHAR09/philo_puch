/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:33:14 by kkouaz            #+#    #+#             */
/*   Updated: 2023/07/18 09:05:23 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	get_actual_time(void)
{
	unsigned long	time;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	time = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	return (time);
}

void	my_usleep(unsigned long time_to_usleep)
{
	unsigned long	time;

	time = get_actual_time() + time_to_usleep;
	while (get_actual_time() <= time)
	{
		usleep(500);
	}
}

void	my_lock(char *flag, int index, unsigned long time,
	pthread_mutex_t *lock)
{
	if (flag[0] == 'e')
		eat(index, time, lock);
	if (flag[0] == 's')
		ft_sleep(index, time, lock);
	if (flag[0] == 't')
		think(index, time, lock);
	if (flag[0] == 'b')
		b_eat(index, time, lock);
	if (flag[0] == 'd')
		die(index, time, lock);
}
