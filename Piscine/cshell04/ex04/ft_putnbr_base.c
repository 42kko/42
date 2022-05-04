/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:12:02 by kko               #+#    #+#             */
/*   Updated: 2022/02/22 18:55:45 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	error_(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == 0 || base[i + 1] == 0)
		return (1);
	while (base[i] != 0)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
		{
			return (1);
		}
		while (base[j] != 0)
		{
			if (base[i] == base[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	len_(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		error;
	int		len;
	int		i;
	long	a;

	i = 0;
	a = nbr;
	error = error_(base);
	len = len_(base);
	if (error == 0)
	{
		if (a < 0)
		{
			write(1, "-", 1);
			a *= -1;
		}
		if (a < len)
			write(1, &base[a], 1);
		if (a >= len)
		{
			ft_putnbr_base(a / len, base);
			ft_putnbr_base(a % len, base);
		}
	}
	return ;
}
