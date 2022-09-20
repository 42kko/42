/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:53:17 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 10:30:14 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_minus(char *str)
{
	int	i;

	i = 0;
	if (str[i] = '-', str[i + 1] == 0)
	{
			ft_putstr_fd("Error\n", 2);
			exit(0);
	}
}

void	err_overlap(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size-- > 1)
	{
		j = i + 1;
		if (arr[i] == arr[j])
		{
			ft_putstr_fd("Error-3\n", 1);
			exit (0);
		}
		i++;
	}
}


void	err(int ac, char **av)
{
	int	i;
	int	state;

	i = 1;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == -1)
		{
			ft_putstr_fd("Error-1\n", 2);
			exit(0);
		}
		else if (ac == 2 && (state != 1 || ft_wordc(av[1], ' ') == 1))
		{
			ft_putstr_fd("Error-2\n", 1);
			exit (0);
		}
		i++;
	}
	return ;
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