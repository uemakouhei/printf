/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:49:08 by kuema             #+#    #+#             */
/*   Updated: 2021/12/09 23:02:00 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef INITIAL_ALLOCATE_SIZE
# define INITIAL_ALLOCATE_SIZE 42
# endif

# define ERR -1

# define SUCCESS 1

# define SET 2

typedef struct err_cout
{
	size_t cpy_bytes;
	size_t mallocsize;
	size_t	index;
	size_t period_size;
	size_t field_size;
	size_t printindex;
	char *set_buf;
	int             sign;
	int             bite;
	int f_sharp;
	int f_zero;
	int f_sp;
	int f_plus;
	int f_bar;
	int f_period;

}	t_cout;

void    *ft_calloc(size_t count, size_t size);
void    *ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
int			ft_printf(const char *s, ...);
size_t		ft_strlen(const char *s);
ssize_t		ft_putunbr(unsigned int n, t_cout *s);
ssize_t		ft_putchar(char c, t_cout *s);
ssize_t		ft_putstr(const char *str, t_cout *s);
ssize_t		ft_putnbr(int n, t_cout *s);
ssize_t		ft_basewrite(unsigned long long n, char *base, t_cout *s);
ssize_t ft_putstr_flagscheck(const char *str, t_cout *s);
ssize_t ft_putnbr(int n, t_cout *s);
ssize_t ft_putunbr(unsigned int n, t_cout *s);
ssize_t ft_basewrite(unsigned long long n, char *base, t_cout *s);
ssize_t ft_setstr(const char *str, t_cout *s);
ssize_t ft_setchar(char c, t_cout *s);
int ft_atoi(const char *a);
int     ft_isprint(int c);
#endif
