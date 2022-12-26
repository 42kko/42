/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:32:04 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 03:57:05 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_free(t_thread_arg **thread_args, pthread_mutex_t	*forks)
// {
// 	free(*thread_args);
// 	free(forks);
// }

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
	exit(0);
}
