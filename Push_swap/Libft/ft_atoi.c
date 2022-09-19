/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:40:21 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 02:12:51 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(void)
{
	ft_putstr_fd("error\n", 1);
	exit(0);
}

size_t	match_nub(const char *nptr, int sign)
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
		ft_exit();
	else if (j >= 20 && sign == -1)
		ft_exit();
	i = match_nub(nptr, sign);
	return (i * sign);
}
