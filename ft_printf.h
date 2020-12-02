/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:12:41 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 17:50:41 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

//int		ft_printf(const char *format, ...);
int		ft_convert_d_and_i(int d);
int		ft_convert_u(int n);
int		ft_convert_c(int c);
int		ft_convert_s(char *str);
int		ft_convert_x(unsigned int n);
int		ft_convert_xcap(unsigned int n);
int		ft_intlen(int n);

#endif
