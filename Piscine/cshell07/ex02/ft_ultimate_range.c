/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:21:49 by kko               #+#    #+#             */
/*   Updated: 2022/02/23 18:07:24 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	a;
	int	*tmp;

	if (max <= min)
		return (0);
	a = max - min;
	*range = (int *)malloc(sizeof(int) * a);
	if (!*range)
		return (-1);
	tmp = *range;
	while (min < max)
		*(tmp++) = min++;
	return (a);
}
