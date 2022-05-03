/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:33:16 by marvin            #+#    #+#             */
/*   Updated: 2022/05/03 17:44:37 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // 지울것
#include <string.h> // 22

#define HEX_x "0123456789abcedf"
#define HEX_X "0123456789ABCEDF"

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

char	*itoa_base(long long n, int base_len, char *base)
{
	char	*ret;
	int		len;

	len = size_base(n, base_len);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
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

char	*itoa_point(size_t n, int base_len, char *base)  // 임시로 만든 p옵션 함수
{
	char	*ret;
	int		len;
	
	len = size_base(n, base_len);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
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

int	print_char(va_list ap)
{
	char	c;
	int		ret;

	c = va_arg(ap, int);
	ret = write(1, &c, 1);
	return (ret);
}

int	print_string(va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char*);
	len = strlen(s); // ft함수로 교체할것
	write(1, s, len);
	return (len);
}

int	print_point(va_list ap)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = (size_t)va_arg(ap, void *);
	s = itoa_point(i, 16, HEX_x);
	j = strlen(s);
	write(1, "0x", 2);
	write(1, s, j);
	free(s);
	return (j + 2);
}

int print_digit(va_list ap)
{
	long long		i;
	char			*s;

	i = va_arg(ap, int);
	s = itoa_base(i, 10, HEX_x);
	write(1, s, strlen(s));
	i = strlen(s);
	free(s);
	return (i);
}

int	print_unsigned_digit(va_list ap)
{
	unsigned int	i;
	char			*s;
 
	i = va_arg(ap, int);
	s = itoa_base(i, 10, HEX_x);
	write(1, s, strlen(s));
	i = strlen(s);
	free(s);
	return (i);
}

int	print_hex(va_list ap, int letter)
{
	long long int	i;
	char			*s;

	i = va_arg(ap, int);
	if (letter == 0)
		s = itoa_base(i, 16, HEX_x);
	else
		s = itoa_base(i, 16, HEX_X);
	write(1, s, strlen(s));
	i = strlen(s);
	free (s);
	return (i);
}

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
		}
	else
		return ; // 해당되는 변수가 없음.
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

int ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	ret = begin_printf(format, ap);
	return (ret);
}

int main()
{
	char s[] = "";
	int i1 = 135513;
	// printf ("%cbc\n", s);
	int i = ft_printf ("%p\n", &i1);
	ft_printf("%d\n",i);
}