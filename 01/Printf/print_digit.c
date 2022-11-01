/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:27:28 by kko               #+#    #+#             */
/*   Updated: 2022/11/01 13:29:27 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_base(long n, int base_len, char *base)
{
	char	*ret;
	int		len;

	len = size_base(n, base_len);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	if (n < 0)
	{
		n = -n;
		ret[0] = '-';
	}
	ret[len] = 0;
	while (n >= base_len)
	{
		ret[--len] = base[n % base_len];
		n /= base_len;
	}
	if (n < base_len)
		ret[--len] = base[n];
	return (ret);
}

int	size_base(long long n, int base_len)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

int	print_digit(va_list ap)
{
	long long		i;
	char			*s;

	i = va_arg(ap, int);
	s = itoa_base(i, 10, HEX_LOW);
	write(1, s, ft_strlen(s));
	i = ft_strlen(s);
	free(s);
	return (i);
}

int	print_unsigned_digit(va_list ap)
{
	unsigned int	i;
	char			*s;

	i = va_arg(ap, int);
	s = itoa_base(i, 10, HEX_LOW);
	write(1, s, ft_strlen(s));
	i = ft_strlen(s);
	free(s);
	return (i);
}

int	print_hex(va_list ap, int letter)
{
	long	i;
	char	*s;

	i = va_arg(ap, unsigned int);
	if (letter == 0)
		s = itoa_base(i, 16, HEX_LOW);
	else
		s = itoa_base(i, 16, HEX_UP);
	write(1, s, ft_strlen(s));
	i = ft_strlen(s);
	free (s);
	return (i);
}
