/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:07:18 by kko               #+#    #+#             */
/*   Updated: 2022/02/19 13:45:31 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!*to_find)
		return (str);
	while (*str)
	{
		j = 0;
		i = 0;
		while (to_find[j] && str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == 0)
				return (str);
		}
		str++;
	}
	return (0);
}
