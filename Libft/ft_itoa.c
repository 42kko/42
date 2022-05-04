/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:16:41 by kko               #+#    #+#             */
/*   Updated: 2022/04/20 16:52:17 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_int(long long n)
{
	int			i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			i;
	long long	j;
	char		*ret;

	j = n;
	i = size_int(j);
	if (n < 0)
		j = -j;
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (!ret)
		return (0);
	if (n < 0)
		ret[0] = '-';
	ret[i] = 0;
	while (j >= 10)
	{
		ret[--i] = (j % 10) + '0';
		j /= 10;
	}
	if (j < 10)
		ret[--i] = j + '0';
	return (ret);
}
