/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:37:51 by kko               #+#    #+#             */
/*   Updated: 2022/02/24 20:38:04 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	strslen(char **strs, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_len(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int	size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*a;

	len = strslen(strs, size);
	i = ft_len(sep);
	if (size == 0)
	{
		a = malloc(1);
		a[0] = '\0';
		return (a);
	}
	a = (char *)malloc(sizeof(char) * (((size - 1) * i) + len) + 1);
	if (a == NULL)
		return (0);
	a[0] = 0;
	i = 0;
	while (i < size)
	{
		a = ft_strcat(a, strs[i]);
		if (i + 1 < size)
			a = ft_strcat(a, sep);
		i++;
	}
	return (a);
}
