/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuema </var/mail/kuema>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 05:12:04 by kuema             #+#    #+#             */
/*   Updated: 2021/12/09 23:03:30 by kuema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static ssize_t ft_memcat(char **buf,t_cout *info,size_t *mallocsize)
{
	void *ptr;

	ptr = NULL;
	if (*buf == NULL)
	{
		*mallocsize = INITIAL_ALLOCATE_SIZE;
		*buf = (char *)ft_calloc(sizeof(char),*mallocsize);
		if (*buf == NULL)
			return (info -> sign = ERR);
	}
	else
	{
		puts("set malloc");
		ptr = (char *)ft_calloc(sizeof(char),(*mallocsize * 2));
		if (ptr == NULL)
		{
			return (info -> sign = ERR);
		}
		ft_memcpy(ptr,*buf,*mallocsize);
		*mallocsize += INITIAL_ALLOCATE_SIZE;
		free(*buf);
		*buf = NULL;
		*buf = (char *)ptr;
	}
	return (SUCCESS);
};
ssize_t	ft_setchar(char c, t_cout *s)
{
	if (s -> sign == ERR)
		return (ERR);
	if (s->cpy_bytes + 2 >= s -> mallocsize)
		if (SUCCESS != ft_memcat(&s->set_buf,s,&s->mallocsize))
			return (s -> sign = ERR);
	s->set_buf[s -> cpy_bytes] = c;
	s->cpy_bytes++;
	return (SUCCESS);
}
