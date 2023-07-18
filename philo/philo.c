/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:40:21 by kkouaz            #+#    #+#             */
/*   Updated: 2023/07/17 11:00:33 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_public	*ft_init(int *args, int ac)
{
	t_public		*public;
	pthread_mutex_t	*fork;
	int				i;
	pthread_mutex_t	*l;

	i = 0;
	l = malloc(sizeof(pthread_mutex_t));
	fork = malloc(args[0] * sizeof(pthread_mutex_t));
	public = fill_struct(args, ac);
	init_forks(fork, args[0]);
	setup(public, fork, args[0]);
	go_philo(l, public, args[0]);
	ft_wait(public, args[0]);
	return (public);
}

int	ft_finish(t_private *private, int i, int j, int n)
{
	while (++i < n)
	{
		pthread_mutex_lock(private[i].time_lock);
		if (get_actual_time() - private[i].last_time_he_ate
			>= private[i].time_to_die)
		{
			pthread_mutex_unlock(private[i].time_lock);
			my_lock("die", private[i].index, private[i].time, private[i].p);
			return (1);
		}
		pthread_mutex_unlock(private[i].time_lock);
		if (private[i].number_of_meals != -1)
		{
			pthread_mutex_lock(private[i].lock);
			if (private[i].times_he_ate >= private[i].number_of_meals)
			{
				pthread_mutex_unlock(private[i].lock);
				j++;
			}
			pthread_mutex_unlock(private[i].lock);
			if (j == n)
				return (1);
		}
	}
	return (0);
}

t_public	*fill_struct(int *args, int ac)
{
	t_public	*public;
	int			i;

	public = malloc(sizeof(t_public));
	public->private = malloc(args[0] * sizeof(t_private));
	i = 0;
	while (i < args[0])
	{
		public->private[i].time_to_die = args[1];
		public->private[i].time_to_eat = args[2];
		public->private[i].time_to_sleep = args[3];
		if (ac == 6)
			public->private[i].number_of_meals = args[4];
		else
			public->private[i].number_of_meals = -1;
		public->private[i].index = i;
		i++;
	}
	return (public);
}
