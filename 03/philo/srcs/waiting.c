/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:54:47 by kko               #+#    #+#             */
/*   Updated: 2023/01/02 15:02:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_anyone_die(t_thread_arg *thread_arg, t_info info)
{
	int				i;
	long long		time_gap;
	struct timeval	cur_time;

	i = 0;
	while (i < info.number)
	{
		gettimeofday(&cur_time, NULL);
		pthread_mutex_lock(&(thread_arg[i].time_mutex));
		time_gap = get_time_gap_ms(thread_arg[i].last_eat, cur_time);
		pthread_mutex_unlock(&(thread_arg[i].time_mutex));
		if (time_gap >= thread_arg[i].info.die)
		{
			print_msg_die(&thread_arg[i], DIE_MES);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static int	is_everyone_eat(t_thread_arg *thread_args, t_info info)
{
	int	i;

	i = 0;
	while (i < info.number)
	{
		pthread_mutex_lock(thread_args->all_eat_mutex);
		if (thread_args[i].is_all_eat == FALSE)
		{
			pthread_mutex_unlock(thread_args->all_eat_mutex);
			return (FALSE);
		}
		pthread_mutex_unlock(thread_args->all_eat_mutex);
		i++;
	}
	pthread_mutex_lock(thread_args->print_mutex);
	return (TRUE);
}

void	waiting_philo(t_thread_arg *thread_args, t_info info)
{
	int	i;

	i = 0;
	while (TRUE)
	{
		if (is_anyone_die(thread_args, info) == TRUE)
			return ;
		if (thread_args->info.must_eat != 0)
		{
			if (is_everyone_eat(thread_args, info) == TRUE)
				return ;
		}
	}
}
