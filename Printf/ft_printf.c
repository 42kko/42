/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:33:16 by marvin            #+#    #+#             */
/*   Updated: 2022/04/26 18:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> // 지울것
#include <string.h> // 22

// #define HEX_LOW {a,b,c,d,e,f}
// #define HEX_UP {A,B,C,D,E,F}

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

// int	print_point(ap)
// {
// 	//포인터의 값은 가리키고잇는 주소값, 또는 포인터의 그 주소값 자체를 받아올수 잇으니 그 int형으로 받아온걸 char 형 16진수로 변경해서 쓸것.
// 	//16진수로 이루어진 값을 int형태의 10진수로 받을테니 그걸 16진수로 교체후 char형으로 교체해야할 것같음.
// }

int print_digit(va_list ap)
{
	int		i;
	char	*s;

	i = va_arg(ap, int);
	s = itoa(i);
}

void	specifier(const char *format, va_list ap, int *ret)
{
	if (*format == 'c')
		*ret += print_char(ap);
	else if (*format == 's')
		*ret += print_string(ap);
	// else if (*format == 'p')
		// ret += print_point(ap);
	else if (*format == 'd' || *format == 'i')
		ret += print_digit(ap);
	// else if (*format == 'u')
	// 	ret += print_unsigned_digit(ap);
	// else if (*format == 'x')
	// 	ret += print_hex(ap, 0);
	// else if (*format == 'X')
	// 	ret += print_hex(ap, 1);
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

	ret == 0;
	va_start(ap, format);
	ret = begin_printf(format, ap);
	return (ret);
}

int main()
{
	char s[] = "ffed";
	// printf ("%cbc\n", s);
	int i = ft_printf ("abd%s\n", s);
	printf("%d\n",i);
}