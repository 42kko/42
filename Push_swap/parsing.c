/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:46:43 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 10:09:20 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((str[i] == '+' || str[i] == '-') && plag == 1)
			return (-1);
		else if (str[i] == '+' || str[i] == '-')
		{
			plag = 1;
			ft_check_minus(str);
		}
		else if ((!ft_isdigit(str[i]) && !ft_isspace(str[i])))
			return (-1);
		else if (ft_isspace(str[i]))
			space = 1;
		else if (ft_isdigit(str[i]) && space == 1)
			return (1);
		i++;
	}
	return (0);
}

int	figures_1(char *av)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (ft_isascii(av[i]) == 1)
	{
		if (ft_isspace(av[i]))
			ret++;
		i++;
	}
	return (++ret);
}

int	figures(int ac, char **av)
{
	int	i;
	int	ret;
	int	state;

	i = 0;
	ret = 0;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == 0)
			ret++;
		else if (state == 1)
		{
			ret += ft_wordc(av[i], ' ');
		}
		i++;
	}
	return (ret);
}

void	ft_putnum(int **ret, int *j, char *av)
{
	int		i;
	int		k;
	int		c;
	char	**split;

	i = *j;
	c = 0;
	k = ft_wordc(av, ' ');
	split = ft_split(av, ' ');
	while (k > 0)
	{
		ret[0][i] = atoi(split[c]);
		i++;
		k--;
		c++;
	}
	*j = i;
}

int	*parsing(int ac, char **av, int *size)
{
	int	*ret;
	int	i;
	int	j;
	int	k;

	i = figures(ac, av);
	*size = i;
	ret = (int *)malloc(sizeof(int) * i);
	i = 0;
	j = 0;
	while (i < ac)
	{
		k = 0;
		if (ft_check_array(av[i]) == 0)
			ret[j++] = ft_atoi(av[i]);
		else if (ft_check_array(av[i]) == 1)
			ft_putnum (&ret, &j, av[i]);
		i++;
	}
	ret[j++] = 0;
	return (ret);
}
