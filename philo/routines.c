/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:39:04 by kkouaz            #+#    #+#             */
/*   Updated: 2023/07/17 00:28:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	eat(int index, unsigned long time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	printf("%lu philo %d has taken a fork\n", get_actual_time() - time, index);
	pthread_mutex_unlock(lock);
}

void	b_eat(int index, unsigned long time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	printf("%lu philo %d has taken a fork\n", get_actual_time() - time, index);
	printf("%lu philo %d is eating\n", get_actual_time() - time, index);
	pthread_mutex_unlock(lock);
}

void	ft_sleep(int index, unsigned long time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	printf("%lu philo %d is sleeping\n", get_actual_time() - time, index);
	pthread_mutex_unlock(lock);
}

void	die(int index, unsigned long time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	printf("%lu philo %d died\n", get_actual_time() - time, index);
}

void	think(int index, unsigned long time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	printf("%lu philo %d is thinking\n", get_actual_time() - time, index);
	pthread_mutex_unlock(lock);
}
