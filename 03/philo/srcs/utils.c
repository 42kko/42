/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:42:46 by kko               #+#    #+#             */
/*   Updated: 2022/12/27 05:34:35 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(long long seconds)
{
	long long		time_gap;
	struct timeval	start_time;
	struct timeval	cur_time;

	gettimeofday(&start_time, NULL);
	while (TRUE)
	{
		gettimeofday(&cur_time, NULL);
		time_gap = get_time_gap_ms(start_time, cur_time);
		if (time_gap >= seconds)
			return ;
		usleep(100);
	}
}

long long	get_time_gap_ms(struct timeval start_time, struct timeval cur_time)
{
	long long	ret;

	ret = (cur_time.tv_usec - start_time.tv_usec) + \
	(cur_time.tv_sec - start_time.tv_sec) * 1000000;
	return (ret / 1000);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static size_t	match_nub(const char *nptr, int sign)
{
	size_t	ret;

	ret = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		ret = (ret * 10) + (*nptr - '0');
		if (ret > 9223372036854775807 && sign == 1)
			return (-1);
		if (ret > 9223372036854775807 && sign == -1)
			return (0);
		nptr++;
	}
	return (ret);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	sign = 1;
	j = 0;
	while ((9 <= *nptr && 13 >= *nptr) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(nptr[j]))
		j++;
	if (j >= 20 && sign == 1)
		return (-1);
	else if (j >= 20 && sign == -1)
		return (0);
	i = match_nub(nptr, sign);
	return (i * sign);
}
