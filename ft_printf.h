/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:12:41 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/05 19:09:41 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_list
{
	va_list 	args;
	int			total;
	int			the_flag[2];
	int 		prec[2];
}				t_list;

t_list 			list;

/*
** Main fonctions
*/

int				ft_printf(const char *format, ...);
void			ft_reset(void);

/*
** Flags fonctions
*/

int				ft_check_all(const char *format);
void			ft_flag_checker(const char *format);

/*
** Percent fonctions
*/

int				ft_percent_all(const char *format);
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

#endif
