/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:51:41 by kko               #+#    #+#             */
/*   Updated: 2022/03/31 21:48:47 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size1;
	size_t	size2;

	if (!s1)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, size1);
	ft_memcpy(ret + size1, s2, size2);
	ret[size1 + size2] = 0;
	return (ret);
}
