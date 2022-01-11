#include "ft_printf_bonus.h"
static void init_flags(t_cout *s)
{
	s->bite = 0;
	s->field_size = 0;
	s->f_bar = 0;
	s->f_period = 0;
	s->f_plus = 0;
	s->f_sharp = 0;
	s->f_sp = 0;
	s->f_zero = 0;
	s->period_size = 0;
	s->index = 0;
	s->mallocsize = 0;
	s->set_buf = NULL;
	s->cpy_bytes = 0;
}
ssize_t ft_putchar(char c, t_cout *s)
{
        if (s -> sign == ERR && c == '\0')
                return (ERR);
        if (s -> printindex > INT_MAX)
        {
                s -> sign = ERR;
                return (ERR);
        }
        s -> printindex++;
        return (write(1, &c, 1));
}

static void ft_putlstr(const char *str, t_cout *s,size_t len)
{
        size_t  index;

        index = 0;
        while (str[index] != '\0' && s -> sign != ERR && len && s->cpy_bytes)
        {
                ft_putchar(str[index], s);
                index++;
                len--;
		s->cpy_bytes--;
        }
	init_flags(s);
}
static void ft_putfield(t_cout *s, size_t sp_index)
{
        while (sp_index && s->f_zero != 2)
        {
                ft_putchar(' ', s);
                sp_index--;
        }
        while (sp_index && s->f_zero == 2)
        {
                ft_putchar('0', s);
                sp_index--;\
        }
}
ssize_t ft_putstr_flagscheck(const char *str, t_cout *s)
{
        size_t s_len;

        if (str == NULL)
                str = "(null)";
        s_len = ft_strlen(str);
        if (s->f_sharp == SET && s->set_buf[0] != '0')
                ft_putlstr("0x", s, 2);
	if (s -> field_size == 0)
        {
                ft_putlstr(str, s, s_len);
                return (SUCCESS);
        }
	if (s->f_bar != SET && s->field_size > s_len)
        {
                ft_putfield(s,s->field_size - s_len);
                ft_putlstr(str, s, s_len);
        }
        if (s->field_size > s_len && s->f_bar == SET)
        {
                ft_putlstr(str, s, s_len);
                ft_putfield(s, s->field_size - s_len);
        }
        ft_putlstr(str,s,s->field_size);
	s->f_sharp = 0;
        return (1);
}
