SRCS    =   ft_printf_utils2.c ft_set_func.c ft_printf_bonus.c ft_printf_utils.c ft_put_func.c ft_set_func2.c

OBJS    = $(SRCS:%.c=%.o)

CC      = gcc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror

NAME    = libftprintf.a

all     : $(NAME)

%.o     : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean   :
	$(RM) $(OBJS)

fclean  : clean
	$(RM) $(NAME)

re      : fclean all

.PHONY: all clean fclean re
