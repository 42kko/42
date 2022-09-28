/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:31:18 by kko               #+#    #+#             */
/*   Updated: 2022/09/28 13:19:32 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	ft_check_minus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && !(ft_isdigit(str[i + 1])))
		{
			ft_putstr_fd("마이너스 하나들어옴\n", 1);
			exit(0);
		}
		i++;
	}
}

int	ft_check_array(char *str)
{
	int	i;
	int	space;
	int	plag;

	i = 0;
	space = 0;
	plag = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			return (1);
		else if (ft_isdigit(str[i]) && space == 1)
			return (1);
		if ((str[i] == '-' || str[i] == '+') && !(ft_isdigit(str[i + 1])))
			err(6);
		i++;
	}
	return (0);
}

int	figures(int ac, char **av)
{
	int	i;
	int	ret;
	int	state;

	i = 1;
	ret = 0;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == 0)
			ret++;
		else if (state == 1)
		{
			ft_check_minus(av[i]);
			ret += ft_wordc(av[i], ' ');
		}
		i++;
	}
	return (ret);
}

int	ft_wordc(const char *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	ret;

	size = ft_strlen(s);
	i = 0;
	ret = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			ret++;
		i++;
	}
	if (i == 0)
		return (0);
	return (ret);
}
