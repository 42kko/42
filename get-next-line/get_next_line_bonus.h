/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 02:16:56 by kko               #+#    #+#             */
/*   Updated: 2022/05/19 02:36:21 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}	t_list;

char	*read_buf(char *save, int fd);
t_list	*new_list(int fd);
t_list	*find_fd(t_list *head, int fd);
t_list	*all_free(t_list *head);
char	*get_line(char *save);
char	*reset_s(char *save);
size_t	num_list(t_list *head, t_list *lst);
void	reset_list(t_list *head, t_list *lst, size_t i);
int		arrange(t_list *head, t_list *lst);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		new_line(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
