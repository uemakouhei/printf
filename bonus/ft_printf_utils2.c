#include "ft_printf_bonus.h"

int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        else
                return (0);
}

static int  ft_isspace(char c)
{
        if (c == ' ' || ('\t' <= c && c <= '\r'))
                return (1);
        else
                return (0);
}

char    *ft_strchr(const char *s, int c)
{
        size_t  i;

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
size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
        {
                i++;
        }
        return (i);
}
int ft_atoi(const char *a)
{
        unsigned int    num;
        size_t i;
        int sign;

        i = 0;
        while (ft_isspace(a[i]))
                i++;
        sign = 1;
        if ((a[i] == '+') || (a[i] == '-'))
        {
                if (a[i++] == '-')
                        sign *= -1;
        }
        num = 0;
        while (ft_isdigit(a[i]))
        {
                num = num * 10 + (a[i] - '0');
                i++;
        }
        return (sign * num);
}


