/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:11:55 by kuema             #+#    #+#             */
/*   Updated: 2021/12/09 23:04:53 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr(const char *str, t_cout *s)
{
	size_t	index;

	index = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", s);
		return (-1);
	}
	while (str[index] != '\0' && s -> sign == 0)
	{
		ft_putchar(str[index], s);
		index++;
	}
	return (index);
}
