/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:32:04 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 05:31:59 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_thread_arg *thread_arg, char *msg)
{
	long long		time_gap;
	struct timeval	cur_time;

	pthread_mutex_lock(thread_arg->print_mutex);
	gettimeofday(&cur_time, NULL);
	time_gap = get_time_gap_ms(thread_arg->info.start_time, cur_time);
	printf("%lld %d %s\n", time_gap, thread_arg->id, msg);
	pthread_mutex_unlock(thread_arg->print_mutex);
}

int	free_init(t_thread_arg **thread_arg, pthread_mutex_t *fork)
{
	free(*thread_arg);
	free(fork);
	return (ARGS_SETTING_ERROR);
}

int	main(int ac, char **av)
{
	t_info			info;
	t_thread_arg	*thread_args;

	if (initial_check(ac, av) < 0)
	{
		printf("err\n");
		return (1);
	}
	if (ft_info(&info, av) < 0)
	{
		printf("err: \n");
		return (1);
	}
	if (set_thread_args(&thread_args, info, 0) == ARGS_SETTING_ERROR)
	{
		printf("err\n");
		return (1);
	}
	make_philosophers(thread_args);
	waiting_philo(thread_args, info);
}
