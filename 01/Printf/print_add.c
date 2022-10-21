/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:28:47 by kko               #+#    #+#             */
/*   Updated: 2022/05/06 23:41:11 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	point_size(size_t n, size_t base_len)
{
	int	i;

	i = 1;
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*itoa_point(size_t n, size_t base_len, char *base)
{
	char	*ret;
	int		define_bit;

	define_bit = point_size(n, base_len);
	ret = (char *)malloc(sizeof(char) * define_bit + 1);
	if (!ret)
		return (0);
	ret[define_bit] = 0;
	while (n >= base_len)
	{
		ret[--define_bit] = base[n % base_len];
		n /= base_len;
	}
	if (n < base_len)
		ret[--define_bit] = base[n];
	return (ret);
}

int	print_point(va_list ap)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = (size_t)va_arg(ap, void *);
	s = itoa_point(i, 16, HEX_LOW);
	j = ft_strlen(s);
	write(1, "0x", 2);
	write(1, s, j);
	free(s);
	return (j + 2);
}
