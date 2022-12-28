/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:37:34 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 05:38:00 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initial_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (-1);
	while (av[i])
	{
		if (ft_atoi(av[i]) < 0)
			return (-1);
		if (ft_atoi(av[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_info(t_info *info, char **av)
{
	memset(info, 0, sizeof(t_info));
	info->number = ft_atoi(av[1]);
	info->die = ft_atoi(av[2]);
	info->eat = ft_atoi(av[3]);
	info->sleep = ft_atoi(av[4]);
	gettimeofday(&info->start_time, NULL);
	if (av[5] != 0)
		info->must_eat = ft_atoi(av[5]);
	return (0);
}

pthread_mutex_t	*get_fork(t_info info, int i)
{
	pthread_mutex_t	*ret;

	ret = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info.number);
	if (ret == NULL)
		return (NULL);
	while (i < info.number)
	{
		pthread_mutex_init(&ret[i], NULL);
		i++;
	}
	return (ret);
}

t_thread_arg	*get_thread(t_info info)
{
	t_thread_arg	*new;

	new = (t_thread_arg *)malloc(sizeof(t_thread_arg) * info.number);
	if (new == NULL)
		return (NULL);
	memset(new, 0, sizeof(t_thread_arg) * info.number);
	return (new);
}

int	set_thread_args(t_thread_arg **thread_arg, t_info info, int i)
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*all_eat_mutex;

	*thread_arg = get_thread(info);
	fork = get_fork(info, 0);
	print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	all_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (thread_arg == NULL || fork == NULL)
		return (free_init(thread_arg, fork));
	pthread_mutex_init(print_mutex, NULL);
	pthread_mutex_init(all_eat_mutex, NULL);
	while (i < info.number)
	{
		(*thread_arg)[i].info = info;
		(*thread_arg)[i].id = i + 1;
		pthread_mutex_init(&((*thread_arg)[i].time_mutex), NULL);
		(*thread_arg)[i].fork = fork;
		(*thread_arg)[i].print_mutex = print_mutex;
		(*thread_arg)[i].all_eat_mutex = all_eat_mutex;
		i++;
	}
	return (ARGS_SETTING_SUCCESS);
}
