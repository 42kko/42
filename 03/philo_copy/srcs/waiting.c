/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:54:47 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 03:49:39 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_anyone_die(t_thread_arg *thread_arg, t_info info)
{
	int				i;
	long long		time_gap;
	struct timeval	cur_time;

	i = 0;
	while (i < info.number)
	{
		gettimeofday(&cur_time, NULL);
		// pthread_mutex_lock(&(thread_args[i].time_mutex));
		time_gap = get_time_gap_ms(thread_arg[i].last_eat, cur_time);
		// pthread_mutex_unlock(&(thread_args[i].time_mutex));
		if (time_gap >= thread_arg[i].info.die)
		{
			print_msg(&thread_arg[i], DIE_MES);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

// int	is_everyone_eat(t_thread_arg *thread_arg, t_info info)
// {
// 	return (FALSE);
// }

void	waiting_philo(t_thread_arg *thread_args, t_info info)
{
	int	i;

	i = 0;
	while (TRUE)
	{
		if (is_anyone_die(thread_args, info) == TRUE)
			return ;
		// if (is_everyone_eat(thread_args, info) == TRUE)
		// 	return ;
	}
}
