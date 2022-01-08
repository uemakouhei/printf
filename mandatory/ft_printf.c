/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:13:02 by kuema             #+#    #+#             */
/*   Updated: 2021/12/09 22:39:27 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formatcheck(const char *str, t_cout *s, va_list list)
{
	if (s == NULL)
		return (0);
	if (*str == 's')
		ft_putstr(va_arg(list, char *), s);
	else if (*str == 'c')
		ft_putchar(va_arg(list, int), s);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(list, int), s);
	else if (*str == 'p')
	{
		ft_putstr("0x", s);
		ft_basewrite(va_arg(list, unsigned long long), "0123456789abcdef", s);
	}
	else if (*str == 'u')
		ft_putunbr(va_arg(list, int), s);
	else if (*str == '%')
		ft_putchar(37, s);
	else if (*str == 'x')
		ft_basewrite(va_arg(list, unsigned int), "0123456789abcdef", s);
	else if (*str == 'X')
		ft_basewrite(va_arg(list, unsigned int), "0123456789ABCDEF", s);
	return (1);
}

static int	doprint(const char *s, va_list list)
{
	t_cout	cout;

	cout = (t_cout){};
	while (*s != '\0')
	{
		if (cout.sign == 1)
			return (-1);
		if (*s == '%')
		{
			s++;
			s += formatcheck(s, &cout, list);
			cout.bite = 0;
		}
		else
			ft_putchar(*s++, &cout);
	}
	return (cout.index);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		returnsize;

	returnsize = 0;
	va_start(list, s);
	if (s != NULL)
		returnsize = doprint(s, list);
	va_end(list);
	return (returnsize);
}
