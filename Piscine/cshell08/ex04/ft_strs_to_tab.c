/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:02:39 by kko               #+#    #+#             */
/*   Updated: 2022/02/23 21:11:19 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*a;
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	a = malloc(sizeof(char) * i + 1);
	if (a == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		a[j] = src[j];
		j++;
	}
	a[j] = 0;
	return (a);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*a;

	a = malloc(sizeof(t_stock_str) * (ac + 1));
	if (a == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		a[i].size = ft_strlen(av[i]);
		a[i].str = (av[i]);
		a[i].copy = ft_strdup(av[i]);
		i++;
	}
	a[i].str = 0;
	return (a);
}
