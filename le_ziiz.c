#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int the_flag[2];
int prec[2];
int new_format;
va_list args;

void	ft_reset(void)
{
	new_format = 0;
	the_flag[0] = 0;
	the_flag[1] = 1;
	prec[0] = 0;
	prec[1] = 0;
}
int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
void	ft_pass(const char **str)
{
	while (ft_isdigit((int)*(*str)) || *(*str) == '-' || *(*str) == '*' || *(*str) == '.')
		(*str)++;
}
void	ft_ajust_var(void)
{
	if (the_flag[0])
	{
		if ((the_flag[0] == 1 || the_flag[0] == 3) && prec[0] < 0)
		{
			the_flag[0] = 2;
			prec[0] *= -1;
		}
		if (the_flag[0] == 2 && prec[0] < 0)
		{
			the_flag[0] = 2;
			prec[0] *= -1;
		}
	}
	if (the_flag[1] == 4 && prec[1] < 0)
		prec[1] = -1;
}
size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	ft_bzero(void *s, size_t n)
{
	char *s2;

	if (!s || n < 0)
		return ;
	s2 = (char *)s;
	while (n-- > 0)
		s2[n] = 0;
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;

	if (!src && !dest)
		return (dest);
	dest2 = (char *)dest;
	src2 = (const char *)src;
	while (n-- > 0)
		dest2[n] = src2[n];
	return ((void *)dest2);
}
void	*ft_calloc(size_t count, size_t size)
{
	void		*dest;

	if (!(dest = malloc(sizeof(void) * (size * count))))
		return (NULL);
	ft_bzero(dest, (count * size));
	return (dest);
}
char	*ft_strchr(const char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)(s + i));
	if (!c)
		return ((char *)(s + i));
	return (NULL);
}
char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	return (dest);
}
int		ft_ispercent(int c)
{
	if (c == 'c')
		return (1);
	if (c == 'd' || c == 'i')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 's')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	return (0);
}
int		ft_index(const char *s, char c)
{
    int i;

    if (!s)
        return (-1);
    i = -1;
    while (s[++i] && !ft_ispercent((int)s[i]))
        if (s[i] == c)
            return (i);
    return ((s[i] == c) ? i : -1);
}
int		ft_intlen(int nb)
{
	int		len;

	len = 0;
	while (nb /= 10)
		len++;
	return (++len);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	if (!s)
		return (NULL);
	(len > ft_strlen(s) - start + 1) ? len = ft_strlen(s) - start : len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(dest = (char *)ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	i = -1;
	while (s[start + (++i)] && len--)
		dest[i] = s[start + i];
	return (dest);
}
char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	int		pos_neg;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	pos_neg = (n < 0) ? 1 : 0;
	if (!(dest = (char *)ft_calloc(sizeof(char), ft_intlen(n) + 1 + pos_neg)))
		return (NULL);
	if (n < 0)
		n = -n;
	i = ft_intlen(n) + pos_neg;
	while (i > 0)
	{
		dest[i-- - 1] = (n % 10) + 48;
		n /= 10;
	}
	if (pos_neg)
		dest[0] = '-';
	return (dest);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dest = (char *)ft_calloc(sizeof(char), size)))
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	return (dest);
}
char	*ft_char_trans(const char *format)
{
	char	*s1;

	if (!(s1 = ft_substr(format, 0, ft_index(format, '*'))))
		return (NULL);
	if (!(s1 = ft_strjoin(s1, ft_itoa(va_arg(args, int)))))	
		return (NULL);
	if (!(s1 = ft_strjoin(s1, ft_strchr(format, '*') + 1)))
		return (NULL);
	return (s1);
}
int		ft_atoi_remix(const char **str)
{
	unsigned long long		nb;
	unsigned long long		nb_tmp;
	int						pos_neg;

	while (*(*str) == '-' || *(*str) == '0')
	{
		pos_neg = -1;
		(*str)++;
	}
	if (*(*str) == '*')
	{
		(*str)++;
		return (va_arg(args, int));
	}
	pos_neg = 1;
	nb = 0;
	while (*(*str) >= '0' && *(*str) <= '9' && *(*str))
	{
		nb_tmp = nb;
		nb = nb * 10 + (*(*str)++ - 48);
		if (nb < nb_tmp || nb > LLONG_MAX)
			return ((pos_neg == 1) ? -1 : 0);
	}
	return ((int)nb * pos_neg);
}
int	ft_get_flag_value(const char **format, int i)
{
	if (the_flag[i] != 3)
		(*format)++;
	return (ft_atoi_remix(format));
}
int	ft_flag_checker(const char *format)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (*format == '0')
			the_flag[i] = 1;
		else if (*format == '-')
			the_flag[i] = 2;
		else if (*format == '.')
			the_flag[i] = 4;
		else if (*format == '*' || ft_isdigit((int)*format))
			the_flag[i] = 3;
		if (the_flag[i])
			prec[i] = ft_get_flag_value(&format, i);
	}
	if (the_flag[0])
		return (1);
	return (0);
}


int		ft_test(const char *format, ...)
{
	va_start(args, format);
	// while (ft_index(format, '*'))
	// {
	// 	new_format++;
	//  	format = ft_char_trans(format);
	// }
	//printf("%s\n", format);
	if (ft_flag_checker(format))
	{
		ft_pass(&format);
		if (!ft_ispercent((int)*format))
		{
			printf("ERROR\n");
			va_end(args);
			return (0);
		}
		ft_ajust_var();
		printf("--- LES FLAGS ---\n");
		printf("%d\n", the_flag[0]);
		printf("%d\n", the_flag[1]);
		printf("\n--- LES PRECISIONS ---\n");
		printf("%d\n", prec[0]);
		printf("%d\n", prec[1]);
	}
	else
		printf("ERROR\n");
	va_end(args);
	return (0);
}

int	main(void)
{
	// char format[100] = "045.2d";
	// ft_test(format, 12, 56);
	printf("%5d", 19123456789);
	return (0);
}

// la commande : c le_ziiz.c && clear && ./a.out
// la  deuxieme commande : gcc le_ziiz.c && clear && ./a.out | cat -e
