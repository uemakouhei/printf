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

#include "ft_printf_bonus.h"
static void set_flags(const char *str, t_cout *s)
{
	if (*str == 'x' || *str == 'X')
	{
		s -> f_sharp++;
	}
	else if(*str == 'i' || *str == 'd' || *str == 'u')
	{
		s -> f_period++;
		s -> f_sp++;
		s -> f_plus++;
	}
	s->f_bar++;
	s->f_zero++;
}
static int	formatcheck(const char *str, t_cout *s, va_list list)
{
	if (s == NULL)
		return (0);
	if (*str == 's')
		ft_setstr(va_arg(list, char *), s);
	else if (*str == 'c')
		ft_setchar(va_arg(list, int), s);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(list, int), s);
	else if (*str == 'p')
	{
		ft_setstr("0x", s);
		ft_basewrite(va_arg(list, unsigned long long), "0123456789abcdef", s);
	}
	else if (*str == 'u')
		ft_putunbr(va_arg(list, int), s);
	else if (*str == '%')
		ft_setchar(37, s);
	else if (*str == 'x')
		ft_basewrite(va_arg(list, unsigned int), "0123456789abcdef", s);
	else if (*str == 'X')
		ft_basewrite(va_arg(list, unsigned int), "0123456789ABCDEF", s);
	set_flags(str,s);
	return (1);
}
static const char* flagscheck(const char *str, t_cout *s)
{       
	if (*str == '-')
		s->f_bar++;
	else if (*str == '#')
		s->f_sharp++;
	else if (*str == '0') 
		s->f_zero++;
	else if (*str == ' ')
		s->f_sp++;
	else if (*str == '+')
		s->f_plus++;
	if (ft_strchr("-#0 +",*str))
		str++;
	if (ft_isdigit(*str))
	{
		s->field_size = ft_atoi(str);
		while(ft_isdigit(*str))
			str++;
	}
	if (*str == '.')
	{
		str++;
		s->f_period++;
		s->period_size = ft_atoi(str);
		while(ft_isdigit(*str))
			str++;
	}
	return (str);
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
			s = flagscheck(s,&cout);
			s += formatcheck(s, &cout, list);
			ft_putstr_flagscheck(cout.set_buf,&cout);
			cout.bite = 0;
			cout.cpy_bytes = 0;
		}
		else
			ft_putchar(*s++, &cout);
	}
	return (cout.printindex);
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
