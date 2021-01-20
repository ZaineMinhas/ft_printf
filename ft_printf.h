/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:12:41 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/20 17:11:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_listx
{
	va_list		args;
	int			total;
	int			flag[2];
	int			prec[2];
	int			percent;
}				t_listx;

t_listx			var;

/*
** Main fonctions
*/

int				ft_printf(const char *format, ...);
void			ft_reset(void);

/*
** Flags fonctions
*/

int				ft_check_all(const char **format);
int				ft_flag_checker(const char **format);
int				ft_flag_error(const char *format);
int				ft_get_flag_value(const char **format, int i);

/*
** Percent fonctions
*/

int				ft_percent_all(int percent);
int				ft_percent_d_and_i(int d);
int				ft_percent_u(int n);
int				ft_percent_c(int c);
int				ft_percent_s(char *str);
int				ft_percent_p(void *adrs);
int				ft_percent_x(unsigned int n);
int				ft_percent_xcap(unsigned int n);

/*
** Additional fonctions
*/

int				ft_intlen(int n);
int				ft_hexlen(unsigned int n);
int				ft_ispercent(int c);
int       		ft_index(char *s, char c);
int				ft_atoi_remix(const char **str);
void			ft_ajust_var(void);
void			ft_second_ajust(void);
void			ft_pass(const char **str);

#endif
