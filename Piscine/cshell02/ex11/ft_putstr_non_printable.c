/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:01:22 by kko               #+#    #+#             */
/*   Updated: 2022/02/16 19:33:25 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wr(char c)
{
	write(1, &c, 1);
}

void	hex(unsigned char c)
{
	if (c < 16)
	{
		write(1, &"0123456789abcdef"[c % 16], 1);
	}
	else if (c >= 16)
	{
		hex(c / 16);
		hex(c % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	long	i;

	i = 0;
	while (str[i])
	{
		if (0 <= str[i] && str[i] <= 15)
		{
			write(1, "\\", 1);
			wr('0');
			hex((unsigned char)str[i]);
		}
		else if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			hex((unsigned char)str[i]);
		}
		else
			wr(str[i]);
		i++;
	}
}
