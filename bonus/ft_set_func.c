#include "ft_printf_bonus.h"
ssize_t ft_putnbr(int n, t_cout *s)
{
        if (n == -2147483648)
        {
                ft_setchar('-', s);
                ft_putunbr(n * -1, s);
        }
        else if (n < 0)
        {
                ft_setchar('-', s);
                ft_putunbr(n, s);
        }
        else if (s -> sign == 0)
        {
                if (n > 9)
                {
                        ft_putnbr(n / 10, s);
                }
                ft_setchar('0' + n % 10, s);
        }
        else
                return (-1);
        return (1);
}
ssize_t ft_putunbr(unsigned int n, t_cout *s)
{
        if (s -> sign == 0)
        {
                if (n > 9)
                {
                        ft_putnbr(n / 10, s);
                }
                ft_setchar('0' + n % 10, s);
        }
        else
                return (-1);
        return (1);
}

ssize_t ft_basewrite(unsigned long long n, char *base, t_cout *s)
{
        size_t  basesize;

        basesize = ft_strlen(base);
        if (s -> sign == 0 && s -> bite != 16)
        {
                if (n > (basesize - 1))
                {
                        s -> bite++;
                        ft_basewrite(n / basesize, base, s);
                }
                ft_setchar(base[n % basesize], s);
        }
        else
                return (-1);
        return (basesize);
}

ssize_t ft_setstr(const char *str, t_cout *s)
{
        size_t  index;

        index = 0;
        if (str == NULL)
                str = "(null)";
        while (str[index] != '\0' && s -> sign == 0)
        {
                ft_setchar(str[index], s);
                index++;
        }
        return (index);
}
