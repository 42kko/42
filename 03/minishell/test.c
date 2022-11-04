/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:48:18 by kko               #+#    #+#             */
/*   Updated: 2022/11/04 16:49:02 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void	handler(int signum)
{
	if (signum != SIGINT)
		return ;
	printf("cntl c\n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
}

int		main(void)
{
	char			*line;

	signal(SIGINT, handler);
	while (1)
	{
		line = readline("prompt> ");
		if (line)
		{
			if (strcmp(line, "exit") == 0)
				exit(0);
			if (ret)
				printf("output> %s\n", line);
			add_history(line);
			free(line);
			line = NULL;
		}
		else
			return (1);
	}
	return (0);
}