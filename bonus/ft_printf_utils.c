#include "ft_printf_bonus.h"

void    *ft_memcpy(void *dst, const void *src, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size)
{
	void    *pt;
	size_t  allocate;

	allocate = count * size;
	if (count == 0 || size == 0)
	{
		pt = malloc(1);
		if (pt == NULL)
		{
			return (NULL);
		}
		ft_bzero(pt, 1);
		return (pt);
	}
	if (allocate / count < size)
		return (NULL);
	pt = malloc(allocate);
	if (pt == NULL)
	{
		return (NULL);
	}
	ft_bzero(pt, allocate);
	return (pt);
}
void    *ft_memcpy(void *dst, const void *src, size_t n)
{
	const char      *srcpt;
	char            *pt;

	srcpt = (char *)src;
	pt = (char *)dst;
	if (pt == NULL && srcpt == NULL)
		return (NULL);
	while (n--)
	{
		*pt++ = *srcpt++;
	}
	return (dst);
}
void    ft_bzero(void *s, size_t n)
{
	char    *pt;

	pt = (char *)s;
	while (n-- != 0)
		*pt++ = '\0';
}
