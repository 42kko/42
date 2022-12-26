/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:58:16 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 03:58:50 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_thread_arg *thread_arg)
{
	int	number = thread_arg->info.number;

	pthread_mutex_lock(&thread_arg->fork[thread_arg->id - 1]);
	print_msg(thread_arg, FRK_MES);
	pthread_mutex_lock(&thread_arg->fork[thread_arg->id % number]);
	print_msg(thread_arg, FRK_MES);
	print_msg(thread_arg, EAT_MES);
	pthread_mutex_lock(&(thread_arg->time_mutex));
	gettimeofday(&(thread_arg->last_eat), NULL);
	pthread_mutex_unlock(&(thread_arg->time_mutex));
	// usleep(thread_arg->info.eat * 1000);
	msleep(thread_arg->info.eat);
}

void	after_eating(t_thread_arg *thread_arg)
{
	int	number = thread_arg->info.number;
	int	must_eat = thread_arg->info.must_eat;

	pthread_mutex_unlock(&thread_arg->fork[thread_arg->id - 1]);
	pthread_mutex_unlock(&thread_arg->fork[thread_arg->id % number]);
	(thread_arg->eat_cnt)++;
	if (must_eat != 0 && thread_arg->eat_cnt == must_eat)
		(thread_arg->info.is_all_eat)++;
}

void	sleeping(t_thread_arg *thread_arg)
{
	print_msg(thread_arg, SLP_MES);
	usleep(thread_arg->info.sleep * 1000);
}

void	thinking(t_thread_arg *thread_arg)
{
	print_msg(thread_arg, THK_MES);
}

void	*philosopher(void *arg)
{
	t_thread_arg	*thread_arg;

	thread_arg = (t_thread_arg *)arg;
	if (thread_arg->id % 2 == 0)
		usleep(100);
	while (TRUE)
	{
		eating(thread_arg);
		after_eating(thread_arg);
		sleeping(thread_arg);
		thinking(thread_arg);
	}
	return (NULL);
}

void	make_philosophers(t_thread_arg *thread_args)
{
	int			i;
	pthread_t	th;

	i = 0;
	gettimeofday(&thread_args[i].info.start_time, NULL);
	while (i < thread_args->info.number)
	{
		gettimeofday(&thread_args[i].last_eat, NULL);
		pthread_create(&th, NULL, philosopher, (void *)&thread_args[i]);
		pthread_detach(th);
		i++;
	}
}