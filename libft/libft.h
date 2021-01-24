/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:53:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/24 18:57:45 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);

char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif
