/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:07:02 by kko               #+#    #+#             */
/*   Updated: 2022/02/19 12:10:38 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	i = len(dest);
	k = len(src);
	if (i > size)
		return (k + size);
	while (j + i + 1 < size && *src)
	{
		dest[i + j] = *src;
		src++;
		j++;
	}
	dest[i + j] = 0;
	return (i + k);
}
