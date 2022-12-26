/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:41:44 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 02:56:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	observe_philosophers(t_thread_arg *thread_args, t_info info)
{
	int	i;

	i = 0;
	while (TRUE)
	{
		if (is_anyone_die(thread_args, info) == TRUE)
			return ;
		if (is_everyone_eat(thread_args, info) == TRUE)
			return ;
	}
}

int	is_anyone_die(t_thread_arg *thread_args, t_info info)
{
	int				i;
	long long		time_gap;
	struct timeval	cur_time;

	i = 0;
	while (i < info.number)
	{
		gettimeofday(&cur_time, NULL);
		pthread_mutex_lock(&(thread_args[i].time_mutex));
		time_gap = get_time_gap_ms(thread_args[i].last_eat_time, cur_time);
		pthread_mutex_unlock(&(thread_args[i].time_mutex));
		if (time_gap >= thread_args[i].info.die)
		{
			print_message(&thread_args[i], DIE_MES);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	is_everyone_eat(t_thread_arg *thread_args, t_info info)
{
	int	i;

	i = 0;
	while (i < info.number)
	{
		if (thread_args[i].is_all_eat == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	*is_over_die_time(void *arg)
{
	long long		time_gap;
	t_thread_arg	*thread_arg;
	struct timeval	cur_time;

	thread_arg = (t_thread_arg *)arg;
	while (TRUE)
	{
		gettimeofday(&cur_time, NULL);
		pthread_mutex_lock(&(thread_arg->time_mutex));
		time_gap = get_time_gap_ms(thread_arg->last_eat_time, cur_time);
		pthread_mutex_unlock(&(thread_arg->time_mutex));
		if (time_gap >= thread_arg->info.die)
		{
			thread_arg->is_die = TRUE;
			time_gap = get_time_gap_ms(thread_arg->start_time, cur_time);
			printf("%lld %d %s\n", time_gap, thread_arg->id, DIE_MES);
			return (NULL);
		}
	}
}
