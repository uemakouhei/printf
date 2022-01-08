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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct err_cout
{
	size_t	index;
	int		sign;
	int		bite;
}	t_cout;

char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
int			ft_printf(const char *s, ...);

size_t		ft_strlen(const char *s);

ssize_t		ft_putunbr(unsigned int n, t_cout *s);
ssize_t		ft_putchar(char c, t_cout *s);
ssize_t		ft_putstr(const char *str, t_cout *s);
ssize_t		ft_putnbr(int n, t_cout *s);
ssize_t		ft_basewrite(unsigned long long n, char *base, t_cout *s);

#endif
