/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utile2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:59:17 by kko               #+#    #+#             */
/*   Updated: 2022/09/28 13:19:21 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_array2(char *str)
{
	int	i;
	int	plag;

	i = 0;
	plag = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && plag == 1)
			err(3);
		else if (str[i] == '-' || str[i] == '+')
			plag = 1;
		else if (!ft_isdigit(str[i]))
			err(3);
		i++;
	}
}

void	ft_check_array3(char *str)
{
	int	i;
	int	plag;
	int	plag1;

	i = 0;
	plag = 0;
	plag1 = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && \
		str[i] != '-' && str[i] != '+')
			err(5);
		i++;
	}
}
