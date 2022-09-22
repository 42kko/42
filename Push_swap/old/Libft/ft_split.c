/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:53:41 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 09:36:08 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(const char *s, size_t i, size_t j, char *ret)
{
	size_t	a;

	a = 0;
	while (a < j)
	{
		ret[a] = s[i + a];
		a++;
	}
	ret[a] = 0;
}

static int	ft_input(const char *s, char c, char **ret, int *val)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
			ret[*val] = (char *)malloc(sizeof(char) * j + 1);
		if (!ret[*val] && j != 0)
		{
			(*val)--;
			return (0);
		}
		if (j != 0)
			ft_putchar (s, i, j, ret[*val]);
		(*val)++;
		i = i + j;
	}
	return (1);
}

static size_t	wordc(const char *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	ret;

	size = ft_strlen(s);
	i = 0;
	ret = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			ret++;
		i++;
	}
	if (i == 0)
		return (0);
	return (ret);
}

static void	memfree(char **ret, int val)
{
	while (val >= 0)
	{
		free(ret[val]);
		val--;
	}
	free(ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		result;
	int		val;
	size_t	word;

	if (!s)
		return (0);
	word = wordc(s, c);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (0);
	ret[word] = 0;
	val = 0;
	result = ft_input(s, c, ret, &val);
	if (result == 0)
	{
		memfree(ret, val);
		return (0);
	}
	return (ret);
}
