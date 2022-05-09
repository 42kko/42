/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 02:16:56 by kko               #+#    #+#             */
/*   Updated: 2022/05/09 22:19:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
// # define BUFFER_SIZE 32

char	*reset_s(char *save);
char	*get_line(char *save);
char	*read_buf(char *save, int fd);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);


#endif
