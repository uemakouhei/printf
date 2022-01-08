#include "ft_printf_bonus.h"
#include <stdio.h>
int main(void)
{
	char str[10] = "12345678";
	printf("   returndigit :%d",ft_printf("%-13s    ",str));
	printf("\n");
	printf("   returndigit :%d",printf("%-13s    ",str));
}
