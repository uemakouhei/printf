/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basewrite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:11:31 by kuema             #+#    #+#             */
/*   Updated: 2021/12/09 23:01:44 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_basewrite(unsigned long long	n, char *base, t_cout *s)
{
	size_t	basesize;

	basesize = ft_strlen(base);
	if (s -> sign == 0 && s -> bite != 16)
	{
		if (n > (basesize - 1))
		{
			s -> bite++;
			ft_basewrite(n / basesize, base, s);
		}
		ft_putchar(base[n % basesize], s);
	}
	else
		return (-1);
	return (basesize);
}
