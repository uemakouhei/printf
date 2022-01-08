/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:12:19 by kuema             #+#    #+#             */
/*   Updated: 2021/12/09 23:01:08 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr(int n, t_cout *s)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10, s);
		ft_putchar('0' - n % 10, s);
	}
	else if (n < 0)
	{
		ft_putchar('-', s);
		ft_putnbr(n *= -1, s);
	}
	else if (s -> sign == 0)
	{
		if (n > 9)
		{
			ft_putnbr(n / 10, s);
		}
		ft_putchar('0' + n % 10, s);
	}
	else
		return (-1);
	return (1);
}
