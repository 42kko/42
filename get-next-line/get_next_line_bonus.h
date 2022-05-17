/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 02:16:56 by kko               #+#    #+#             */
/*   Updated: 2022/05/17 22:13:07 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}	t_list;

char	*reset_s(char *save, t_list *lst_buf);
char	*get_line(char *save);
char	*read_buf(char *save, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
t_list	*find_fd(t_list *lst_buf, int fd);
t_list	*new_lst(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	all_free(t_list *lst);

#endif
