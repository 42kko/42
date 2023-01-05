/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:58:16 by kko               #+#    #+#             */
/*   Updated: 2023/01/05 11:34:51 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_thread_arg *thread_arg)
{
	int	number;

	number = thread_arg->info.number;
	pthread_mutex_lock(&thread_arg->fork[thread_arg->id - 1]);
	print_msg(thread_arg, FRK_MES);
	pthread_mutex_lock(&thread_arg->fork[thread_arg->id % number]);
	print_msg(thread_arg, FRK_MES);
	print_msg(thread_arg, EAT_MES);
	pthread_mutex_lock(&(thread_arg->time_mutex));
	gettimeofday(&(thread_arg->last_eat), NULL);
	pthread_mutex_unlock(&(thread_arg->time_mutex));
	msleep(thread_arg->info.eat);
}

static void	after_eating(t_thread_arg *thread_arg)
{
	int	number;
	int	must_eat;

	number = thread_arg->info.number;
	must_eat = thread_arg->info.must_eat;
	pthread_mutex_unlock(&thread_arg->fork[thread_arg->id - 1]);
	pthread_mutex_unlock(&thread_arg->fork[thread_arg->id % number]);
	(thread_arg->eat_cnt)++;
	if (must_eat != 0 && thread_arg->eat_cnt == must_eat)
	{
		pthread_mutex_lock(thread_arg->all_eat_mutex);
		thread_arg->is_all_eat = TRUE;
		pthread_mutex_unlock(thread_arg->all_eat_mutex);
	}
	print_msg(thread_arg, SLP_MES);
	msleep(thread_arg->info.sleep);
}

static void	thinking(t_thread_arg *thread_arg)
{
	print_msg(thread_arg, THK_MES);
}

static void	*philosopher(void *arg)
{
	t_thread_arg	*thread_arg;

	thread_arg = (t_thread_arg *)arg;
	if (thread_arg->id % 2 == 0)
		usleep(10000);
	while (TRUE)
	{
		eating(thread_arg);
		after_eating(thread_arg);
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
	if (thread_args->info.number == 1)
	{
		print_msg(thread_args, FRK_MES);
		gettimeofday(&thread_args[i].last_eat, NULL);
		return ;
	}
	while (i < thread_args->info.number)
	{
		gettimeofday(&thread_args[i].last_eat, NULL);
		pthread_create(&th, NULL, philosopher, (void *)&thread_args[i]);
		pthread_detach(th);
		i++;
	}
}
