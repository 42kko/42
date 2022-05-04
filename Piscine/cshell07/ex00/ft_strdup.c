/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:28:33 by kko               #+#    #+#             */
/*   Updated: 2022/04/03 15:32:30 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	while (src[i])
	{
		i++;
	}
	a = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		a[j] = src[j];
		j++;
	}
	a[j] = 0;
	return (a);
}