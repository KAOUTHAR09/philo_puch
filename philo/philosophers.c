/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 07:24:13 by kkouaz            #+#    #+#             */
/*   Updated: 2023/07/18 09:02:21 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	init_forks(pthread_mutex_t *fork, int n)
{
	int				i;

	i = 0;
	while (i < n)
		pthread_mutex_init(&fork[i++], NULL);
}

void	setup(t_public *public, pthread_mutex_t *fork, int n)
{
	int				i;

	i = 0;
	while (i < n)
	{
		public->private[i].l_fork = &fork[i];
		if (i == n - 1)
			public->private[i].r_fork = &fork[0];
		else
			public->private[i].r_fork = &fork[i + 1];
		i++;
	}
	i = 0;
	while (i < n)
	{
		public->private[i].time = get_actual_time();
		public->private[i].last_time_he_ate = get_actual_time();
		public->private[i].times_he_ate = 0;
		i++;
	}
}

void	*routine(void *str)
{
	t_private	*private;

	private = str;
	while (1)
	{
		pthread_mutex_lock(private->l_fork);
		my_lock("eat", private->index, private->time, private->p);
		pthread_mutex_lock(private->r_fork);
		my_lock("b_eat", private->index, private->time, private->p);
		pthread_mutex_lock(private->lock);
			private->times_he_ate++;
		pthread_mutex_unlock(private->lock);
		pthread_mutex_lock(private->time_lock);
		private->last_time_he_ate = get_actual_time();
		pthread_mutex_unlock(private->time_lock);
		my_usleep(private->time_to_eat);
		pthread_mutex_unlock(private->l_fork);
		pthread_mutex_unlock(private->r_fork);
		my_lock("sleep", private->index, private->time, private->p);
		my_usleep(private->time_to_sleep);
		my_lock("think", private->index, private->time, private->p);
	}
	return (NULL);
}

void	go_philo(pthread_mutex_t *l, t_public *public, int n)
{
	int				i;
	pthread_mutex_t	*l1;
	pthread_mutex_t	*l2;

	l1 = malloc(sizeof(pthread_mutex_t));
	l2 = malloc(sizeof(pthread_mutex_t));
	i = 0;
	pthread_mutex_init(l, NULL);
	pthread_mutex_init(l1, NULL);
	pthread_mutex_init(l2, NULL);
	while (i < n)
	{
		public->private[i].lock = l;
		public->private[i].p = l1;
		public->private[i].time_lock = l2;
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_create(&public->private[i].philo, NULL, routine,
			&public->private[i]);
		usleep(500);
		i++;
	}
}

void	ft_wait(t_public *public, int n)
{
	int	i;
	int	j;

	i = -1;
	while (1)
	{
		j = 0;
		i = -1;
		if (ft_finish(public->private, i, j, n))
			break ;
	}
}
