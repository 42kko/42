/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:58:08 by kko               #+#    #+#             */
/*   Updated: 2022/04/12 15:02:16 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*start;

	start = (t_list *)malloc(sizeof(t_list));
	if (!start)
		return (0);
	start->content = content;
	start->next = 0;
	return (start);
}
