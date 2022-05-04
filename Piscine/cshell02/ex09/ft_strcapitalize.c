/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:37:42 by kko               #+#    #+#             */
/*   Updated: 2022/02/19 14:07:38 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	non_word(char *c)
{
	if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
		return (0);
	else if (*c >= '0' && *c <= '9')
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	state;

	i = 0;
	state = 1;
	while (str[i])
	{
		if (non_word(&str[i]))
			state = 1;
		else if (state == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			state = 0;
		}
		else if (state == 1 && !(str[i] >= 'a' && str[i] <= 'z'))
			state = 0;
		else if (state == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
