/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:46:24 by kuema             #+#    #+#             */
/*   Updated: 2021/11/02 16:46:35 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
