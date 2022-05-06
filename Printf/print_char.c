/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:25:42 by kko               #+#    #+#             */
/*   Updated: 2022/05/06 23:31:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	s = va_arg(ap, char *);
	if (!s)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
