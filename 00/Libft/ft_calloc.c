/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:34:59 by kko               #+#    #+#             */
/*   Updated: 2022/04/20 21:36:58 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc((number) * size);
	if (!p)
		return (0);
	while (i < (number * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
