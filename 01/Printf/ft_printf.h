/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:27 by kko               #+#    #+#             */
/*   Updated: 2022/11/01 13:00:27 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
// # include "../Libft/libft.h"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		size_base(long long n, int base_len);
int		system_bit(void);
char	*itoa_base(long n, int base_len, char *base);
char	*itoa_point(size_t n, size_t base_len, char *base);
int		print_char(va_list ap);
int		print_string(va_list ap);
int		print_point(va_list ap);
int		print_digit(va_list ap);
int		print_unsigned_digit(va_list ap);
int		print_hex(va_list ap, int letter);
void	specifier(const char *format, va_list ap, int *ret);
int		begin_printf(const char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif
