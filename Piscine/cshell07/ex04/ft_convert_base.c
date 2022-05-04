/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:38:08 by kko               #+#    #+#             */
/*   Updated: 2022/02/24 20:37:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*sign_(char *str, int *i);
int		error_(char *base);
int		find_(char str, char *base);
int		len_(char *base);
int		ft_atoi_base(char *str, char *base);

int	size(char *base, long long *nb, int *k)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	num;

	i = 0;
	j = 0;
	if (*nb < 0)
	{
		i += 1;
		*nb *= -1;
		*k = 1;
	}
	num = *nb;
	while (base[j])
		j++;
	while (num > j)
	{
		num = num / j;
		i++;
	}
	i += 1;
	return (i);
}

char	*last(int j, char *base_to, int nb, int len)
{
	int		i;
	char	*b[len];

	i = 0;
	while (len-- > 0)
	{
		b[len] = base_to[nb % i];
		nb = nb / i;
	}
	if (j == 1)
		b[0] = '-';
	return (b);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		nb;
	unsigned int	len;
	char			*a;
	int				j;

	j = 0;
	nb = ft_atoi_base(nbr, base_from);
	if (error_(base_to) == 1 || error_(base_from) == 1)
		return (0);
	len = size(base_to, &nb, &j);
	a = (char *)malloc((sizeof(char) * len) + 1);
	if (a == NULL)
		return (0);
	a[len] = 0;
	a = last(j, base_to, nb, len);
	return (a);
}
