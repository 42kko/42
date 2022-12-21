/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:36:19 by kko               #+#    #+#             */
/*   Updated: 2022/12/21 22:03:32 by kko              ###   ########.fr       */
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
	int	number;
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}	t_info;

typedef struct s_thread_arg
{
	t_info			info;
	int				id;
	int				is_die;
	int				is_all_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	time_mutex;
	struct timeval	start_time;
	struct timeval	last_eat_time;
	int				eat_count;
}	t_thread_arg;

void			msleep(long long seconds);
long long		get_time_gap_ms(struct timeval start_time, \
struct timeval cur_time);
int				ft_isdigit(int c);
size_t			match_nub(const char *nptr, int sign);
int				ft_atoi(const char *nptr);
void			make_philosophers(t_thread_arg *thread_args);
int				set_thread_args(t_thread_arg **thread_args, t_info info);
pthread_mutex_t	*make_forks(t_info info);
int				initial_check(int ac, char **av);
int				ft_info(t_info *info, char **av);
void			*philosopher(void *arg);
void			eating(t_thread_arg *thread_arg);
void			after_eating(t_thread_arg *thread_arg);
void			sleeping(t_thread_arg *thread_arg);
void			thinking(t_thread_arg *thread_arg);
void			observe_philosophers(t_thread_arg *thread_args, t_info info);
int				is_anyone_die(t_thread_arg *thread_args, t_info info);
int				is_everyone_eat(t_thread_arg *thread_args, t_info info);
void			*is_over_die_time(void *arg);
void			ft_free(t_thread_arg **thread_args, \
pthread_mutex_t	*forks);

#endif