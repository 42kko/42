/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:21:43 by kko               #+#    #+#             */
/*   Updated: 2022/05/06 23:24:25 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier(const char *format, va_list ap, int *ret)
{
	if (*format == 'c')
		*ret += print_char(ap);
	else if (*format == 's')
		*ret += print_string(ap);
	else if (*format == 'p')
		*ret += print_point(ap);
	else if (*format == 'd' || *format == 'i')
		*ret += print_digit(ap);
	else if (*format == 'u')
		*ret += print_unsigned_digit(ap);
	else if (*format == 'x')
		*ret += print_hex(ap, 0);
	else if (*format == 'X')
		*ret += print_hex(ap, 1);
	else if (*format == '%')
	{
		write(1, "%", 1);
		format++;
		*ret = *ret + 1;
	}
	else
		return ;
}

int	begin_printf(const char *format, va_list ap)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier(format, ap, &ret);
		}
		else
		{
			write(1, format, 1);
			ret++;
		}
		format++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	ret = begin_printf(format, ap);
	va_end(ap);
	return (ret);
}
