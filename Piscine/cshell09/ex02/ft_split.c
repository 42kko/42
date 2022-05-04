/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:41:00 by kko               #+#    #+#             */
/*   Updated: 2022/02/24 18:26:14 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == 0)
		return (1);
	return (0);
}

int	word(char *str, char *charset)
{
	int	i;
	int	wd;

	i = 0;
	wd = 0;
	while (str[i])
	{
		if (sep(str[i + 1], charset) == 1 && sep(str[i], charset) == 0)
		{
			wd++;
		}
		i++;
	}
	return (wd);
}

void	size(char **a, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (sep(str[i], charset) == 0)
			j++;
		if (sep(str[i + 1], charset) == 1 && sep(str[i], charset) == 0)
		{
			a[k] = (char *)malloc(sizeof(char) * j + 1);
			a[k][j] = 0;
			j = 0;
			k++;
		}
		i++;
	}
}

char	**ft_strcat(char *str, char *charset, char **a)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (sep(str[i], charset) == 0)
		{
			a[j][k] = str[i];
			k++;
		}
		if (str[i] != 0)
		{
			if (sep(str[i + 1], charset) == 1 && sep(str[i], charset) == 0)
			{
				j++;
				k = 0;
			}
		}
		i++;
	}
	return (a);
}

char	**ft_split(char *str, char *charset)
{
	int		wd;
	char	**a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	wd = word(str, charset);
	a = (char **)malloc(sizeof(char *) * (wd + 1));
	if (a == NULL)
		return (0);
	a[wd] = 0;
	size(a, str, charset);
	a = ft_strcat(str, charset, a);
	return (a);
}
