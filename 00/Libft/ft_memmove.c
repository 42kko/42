/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:08:31 by kko               #+#    #+#             */
/*   Updated: 2022/04/03 17:02:14 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_d;
	const char	*tmp_s;

	if (!dst && !src)
		return (0);
	tmp_d = dst;
	tmp_s = src;
	if (dst < src)
	{
		while (len--)
			*tmp_d++ = *tmp_s++;
	}
	else
	{
		tmp_d += len;
		tmp_s += len;
		while (len--)
			*--tmp_d = *--tmp_s;
	}
	return (dst);
}
