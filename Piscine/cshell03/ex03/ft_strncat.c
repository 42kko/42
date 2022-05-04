/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:07:26 by kko               #+#    #+#             */
/*   Updated: 2022/02/17 17:05:19 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (dest[i])
	{
		i++;
	}
	while (*src && k < nb)
	{
		dest[i] = *src;
		src++;
		i++;
		k++;
	}
	dest[i] = 0;
	return (dest);
}
