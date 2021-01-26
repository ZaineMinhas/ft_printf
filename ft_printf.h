/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:12:41 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/26 19:31:47 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

va_list		g_args;
int			g_flag[2];
int			g_prec[2];
int			g_percent;
int			g_check;

/*
** Main fonctions
*/

int				ft_printf(const char *format, ...);
void			ft_reset(void);
int				ft_check_all(const char **format);
int				ft_percent_all(int percent);

/*
** Flags fonctions
*/

int				ft_flag_checker(const char **format);
int				ft_flag_error(const char *format);
int				ft_get_flag_value(const char **format, int i);

/*
** Percent fonctions
*/

int				ft_percent_d_and_i(int d);
int				ft_percent_u(int n);
int				ft_percent_c(int c);
int				ft_percent_s(char *str);
int				ft_percent_p(void *adrs);
int				ft_percent_x(unsigned int n, char *base);
int				ft_percent_xcap(unsigned int n);
int				ft_percent_percent(void);

/*
** Additional fonctions
*/

int				ft_intlen(int n);
int				ft_intlen_ui(unsigned int n);
int				ft_hexlen(unsigned int n);
int				ft_hexlen_ul(unsigned long n);
int				ft_ispercent(int c);
int				ft_atoi_remix(const char **str);
void			ft_ajust_var(void);
void			ft_second_ajust(void);
int				ft_putnbr_ui(int n);
void			ft_putnbr_remix(unsigned int n);
int				ft_putstr_size(char *s, int prec);

#endif
