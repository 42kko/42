/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:15:38 by kko               #+#    #+#             */
/*   Updated: 2022/02/16 17:45:54 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*set_combn(char *a, int max, int index)
{
	if (a[index - 1] == '9' - (max - index))
		set_combn(a, max, index - 1);
	else
	{
		a[index - 1] += 1;
		while (index < max)
		{
			a[index] = a[index - 1] + 1;
			index++;
		}
	}
	return (a);
}

void	ft_print_combn(int n)
{
	char	a[9];
	char	*comb;
	int		i;

	i = 0;
	while (i < n)
	{
		a[i] = i + '0';
		i++;
	}
	comb = a;
	while (a[0] + n != 58)
	{
		write(1, comb, n);
		write(1, ", ", 2);
		comb = set_combn(comb, n, n);
	}
	write(1, comb, n);
}
