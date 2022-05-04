/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:38:25 by kko               #+#    #+#             */
/*   Updated: 2022/02/22 17:25:09 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*sign_(char *str, int *i)
{
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			*i *= -1;
		}
		str++;
	}
	return (str);
}

int	error_(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == 0 || base[i + 1] == 0)
		return (1);
	while (base[i] != 0)
	{
		j = 1 + i;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (1);
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

int	find_(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	len_(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;
	int	error;
	int	find;
	int	len;

	find = 0;
	sign = 1;
	str = sign_(str, &sign);
	error = error_(base);
	find = find_(*str, base);
	len = len_(base);
	nb = 0;
	if (error == 0)
	{
		while (find != -1)
		{
			nb = (nb * len) + find;
			str++;
			find = find_(*str, base);
		}
		return (nb *= sign);
	}
	return (0);
}
