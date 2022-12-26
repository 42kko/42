/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:42:59 by kko               #+#    #+#             */
/*   Updated: 2022/12/26 23:28:22 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	eating(t_thread_arg *thread_arg)
{
	int				id;
	int				number;

	id = thread_arg->id;
	number = thread_arg->info.number;
	pthread_mutex_lock(&(thread_arg->forks[id - 1]));
	print_message(thread_arg, FRK_MES);
	pthread_mutex_lock(&(thread_arg->forks[id % number]));
	print_message(thread_arg, FRK_MES);
	print_message(thread_arg, EAT_MES);
	pthread_mutex_lock(&(thread_arg->time_mutex));
	gettimeofday(&(thread_arg->last_eat_time), NULL);
	pthread_mutex_unlock(&(thread_arg->time_mutex));
	msleep(thread_arg->info.eat);
}

void	after_eating(t_thread_arg *thread_arg)
{
	int	id;
	int	number;
	int	must_eat;

	id = thread_arg->id;
	number = thread_arg->info.number;
	must_eat = thread_arg->info.must_eat;
	pthread_mutex_unlock(&(thread_arg->forks[id - 1]));
	pthread_mutex_unlock(&(thread_arg->forks[id % number]));
	(thread_arg->eat_count)++;
	if (must_eat != 0 && thread_arg->eat_count >= must_eat)
		thread_arg->is_all_eat = TRUE;
}

void	sleeping(t_thread_arg *thread_arg)
{
	print_message(thread_arg, SLP_MES);
	msleep(thread_arg->info.sleep);
}

void	thinking(t_thread_arg *thread_arg)
{
	print_message(thread_arg, THK_MES);
}
