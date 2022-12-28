/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:45:32 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 04:03:01 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	make_philosophers(t_thread_arg *thread_args)
{
	int			i;
	pthread_t	th;

	i = 0;
	while (i < thread_args->info.number)
	{
		pthread_create(&th, NULL, philosopher, (void *)&thread_args[i]);
		pthread_detach(th);
		i++;
	}
}

int	set_thread_args(t_thread_arg **thread_args, t_info info)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	struct timeval	start_time;

	*thread_args = malloc(sizeof(t_thread_arg) * info.number);
	forks = make_forks(info);
	print_mutex = malloc(sizeof(pthread_mutex_t));
	if (*thread_args == NULL || forks == NULL || print_mutex == NULL)
	{
		ft_free(thread_args, forks);
		return (ARGS_SETTING_ERROR);
	}
	i = 0;
	gettimeofday(&start_time, NULL);
	pthread_mutex_init(print_mutex, NULL);
	while (i < info.number)
	{
		memset(&((*thread_args)[i]), 0, sizeof(t_thread_arg));
		(*thread_args)[i].info = info;
		(*thread_args)[i].id = i + 1;
		(*thread_args)[i].forks = forks;
		pthread_mutex_init(&((*thread_args)[i].time_mutex), NULL);
		(*thread_args)[i].print_mutex = print_mutex;
		(*thread_args)[i].start_time = start_time;
		(*thread_args)[i].last_eat_time = start_time;
		i++;
	}
	return (ARGS_SETTING_SUCCESS);
}

pthread_mutex_t	*make_forks(t_info info)
{
	int				i;
	pthread_mutex_t	*ret;

	ret = malloc(sizeof(pthread_mutex_t) * info.number);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < info.number)
	{
		pthread_mutex_init(&(ret[i]), NULL);
		i++;
	}
	return (ret);
}

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
	if (av[5] != 0)
		info->must_eat = ft_atoi(av[5]);
	return (0);
}
