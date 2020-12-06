/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:12:41 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/06 17:45:42 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_percent_d_and_i(int d);
int		ft_percent_u(int n);
int		ft_percent_c(int c);
int		ft_percent_s(char *str);
int		ft_percent_p(void *adrs);
int		ft_percent_x(unsigned int n);
int		ft_percent_xcap(unsigned int n);
int		ft_hexlen(int n);
int		ft_intlen(int n);

#endif
