/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:03:20 by kko               #+#    #+#             */
/*   Updated: 2022/02/21 11:47:18 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	i;

	i = 2;
	if (nb <= 1)
		return (2);
	while (i * i <= (long long)nb)
	{
		if (nb % i == 0)
			return (ft_find_next_prime(++nb));
		i++;
	}
	return (nb);
}
