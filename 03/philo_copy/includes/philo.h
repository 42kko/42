/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:36:19 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 03:11:31 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ARGS_SETTING_ERROR 0
# define ARGS_SETTING_SUCCESS 1
# define FRK_MES "has taken a fork"
# define EAT_MES "is eating"
# define SLP_MES "is sleeping"
# define THK_MES "is thinking"
# define DIE_MES "died"

typedef struct s_info
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				is_all_eat;
	struct timeval	start_time;
}	t_info;

typedef struct s_thread_arg
{
	t_info			info;
	int				id;
	int				eat_cnt;
	int				is_die;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	time_mutex;
	struct timeval	last_eat;
}	t_thread_arg;

// void	ft_free(t_thread_arg **thread_args, pthread_mutex_t	*forks);

void	make_philosophers(t_thread_arg *thread_args);

int	initial_check(int ac, char **av);
int	ft_info(t_info *info, char **av);
pthread_mutex_t	*get_fork(t_info info, int i);
t_thread_arg	*get_thread(t_info info);
int	free_init(t_thread_arg **thread_arg, pthread_mutex_t *fork);
int	set_thread_args(t_thread_arg **thread_arg, t_info info, int i);

void	msleep(long long seconds);
int	ft_atoi(const char *nptr);
long long	get_time_gap_ms(struct timeval start_time, struct timeval cur_time);
void	print_msg(t_thread_arg *thread_arg, char *msg);

void	waiting_philo(t_thread_arg *thread_args, t_info info);

#endif