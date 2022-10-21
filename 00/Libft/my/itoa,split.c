/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa,split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:13:49 by kko               #+#    #+#             */
/*   Updated: 2022/04/07 21:33:51 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_itoa.c"
#include "ft_split.c"
#include "fft_split.c"
#include "ft_strlcpy.c"
#include "ft_memcpy.c"
#include "ft_strlen.c"
#include "ft_strtrim.c"
#include "ft_strchr.c"
#include "ft_memmove.c"

int main()
{
	printf("=====itoa=====\n");
	{
		int i;
		char *s;

		i = -2147483648;
		s = ft_itoa(i);
		printf("%s\n", s);
	}
	printf("=====split=====\n");
	{
		char **ret;
		char **ret1;
		char *s = "  plit       this for   me  !  ";

		ret = ft_split(s, ' ');
		ret1 = fft_split(s, ' ');
		int i = 0;
		while(ret[i])
		{
			printf("%s / " ,ret[i]);
			i++;
		}
		printf("\n");
		i = 0;
		while(ret1[i])
		{
			printf("%s / " ,ret1[i]);
			i++;
		}
	}
	return 0;
}