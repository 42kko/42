/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:48:18 by kko               #+#    #+#             */
/*   Updated: 2022/10/31 11:07:18 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main()
{
	char *a;

	while (1)
	{
		a = readline("prompt :");
		if (a)
			printf("%s\n",a);
		else
			break;
	}
	free(a);
	return (0);
}