/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:01:32 by kko               #+#    #+#             */
/*   Updated: 2022/03/31 20:13:08 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s1)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	size = j;
	while (s1[i] && ft_strchr(set, s1[i]) && size > i)
		i++;
	while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
		j--;
	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1 + i, j - i);
	ret[j - i] = 0;
	return (ret);
}
