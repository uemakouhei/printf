SRCS    =    ft_printf.c ft_putstr.c ft_putchar.c ft_strchr.c ft_strlen.c ft_isdigit.c ft_putnbr.c ft_putunbr.c ft_basewrite.c 

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
