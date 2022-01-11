#include<stdio.h>
#include<string.h>
#include <assert.h>
#include "ft_printf_bonus.h"

void testsuccess()
{
	puts("\x1b[35m");
	puts("OK TEST SUCCESS!\n");
	puts("\x1b[39m");
}
void testfailled()
{
	puts("\x1b[32m");
	puts("TEST FAILLED!\n");
	puts("\x1b[39m");
}
int teststart(char *testname,int testindex)
{
	printf("\x1b[31m");
	printf("%i : ----------%s----------\n",testindex,testname);
	printf("\x1b[39m");
	fflush(stdout);
	return (1);
}
int basictest()
{
	char libbuf[8192];
	char str[] = "\t\n\t\b%%";
	char str2[] = "\0\0\0\0\0";
	char a = '\n';
	int d = INT_MAX;
	int e = INT_MIN;
	long f = LONG_MAX ;
	int j;
	unsigned int number = UINT_MAX + 1;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%s%%%c%%%d%%%i%%%x%%%X%%%p%%%u\n",str,a,d,e,(int)f,(int)f,str2,number);
	fflush(stdout);
	char ftbuf[8192];
	int i;
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	i = ft_printf("%s%%%c%%%d%%%i%%%x%%%X%%%p%%%u\n",str,a,d,e,(int)f,(int)f,str2,number);
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else 
	{
		testfailled();
		puts("hints-> control char || INT_MAX..MIN");
		return (0);
	}
}
int ctest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	int s,b,c;

	i = 0;
	j = 0;
	s = '\0';
	b = 13;
	c = 100;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%c%c%c\n",s,b,c);
	fflush(stdout);	
	i = ft_printf("%c%c%c\n",s,b,c);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> c = 1000");
		return (0);
	}
}
int dtest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	long s,b,c;

	i = 0;
	j = 0;
	s = LONG_MIN;
	b = LONG_MAX;
	c = 0;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%d%d%d\n",(int)s,(int)b,(int)c);
	fflush(stdout);
	i = ft_printf("%d%d%d\n",(int)s,(int)b,(int)c);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> (int)LONG_MIN .. MAX || zero");
		return (0);
	}
}
int xtest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	int s,b,c;

	i = 0;
	j = 0;
	s = 0x0;
	b = INT_MAX;
	c = INT_MIN;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%x%x%x\n",s,b,c);
	fflush(stdout);
	i = ft_printf("%x%x%x\n",s,b,c);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> 0x0 || INT_MIN..MAX");
		return (0);
	}
}
int Xtest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	int s,b,c;

	i = 0;
	j = 0;
	s = 0x0;
	b = INT_MAX;
	c = INT_MIN;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%X%X%X\n",s,b,c);
	fflush(stdout);
	i = ft_printf("%X%X%X\n",s,b,c);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> INT_MIN..MAX || 0x0");
		return (0);
	}
}
int itest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	int s,b,c;

	i = 0;
	j = 0;
	s = 00;
	b = 010;
	c = 0x0;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%i%i%i\n",s,b,c);
	fflush(stdout);
	i = ft_printf("%i%i%i\n",s,b,c);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> zero || 8base");
		return (0);
	}
}

int stest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	char s[] = "                 %% ";
	char s2[] = "                 \n";
	char s3[] = "                   %%s";

	i = 0;
	j = 0;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%s%s%s\n",s,s2,s3);
	fflush(stdout);
	i = ft_printf("%s%s%s\n",s,s2,s3);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> space back char");
		return (0);
	}
}

int ptest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	char *s = NULL;
	char s2[] = "";
	int s3;
	s3 = 0;
	i = 0;
	j = 0;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%p%p%p\n",s,s2,&s3);
	fflush(stdout);
	i = ft_printf("%p%p%p\n",s,s2,&s3);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> NULL || "" || 0");
		return (0);
	}
}
int utest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	unsigned int d,s,k;
	i = 0;
	j = 0;

	d = -1;
	s = UINT_MAX;
	k = UINT_MAX + 1;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%u%u%u\n",d,s,k);
	fflush(stdout);
	i = ft_printf("%u%u%u\n",d,s,k);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> INT_MIN .. MAX || INT_MAXOVER");
		return (0);
	}
}
int escapetest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j,k;
	unsigned int d,s;
	char str[] = "test";
	i = 0;
	j = 0;

	d = UINT_MAX;
	s = 0;
	k = -136;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	j = printf("%%%%%s%%\n",str);
	fflush(stdout);
	i = ft_printf("%%%%%s%%\n",str);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> %%%%%%%%s%%");
		return (0);
	}
}

int discordtest()
{
	char libbuf[8192];
	char ftbuf[8192];
	int i,j;
	char *s = NULL;
	unsigned int index = 42;
	setvbuf(stdout, libbuf, _IOFBF, sizeof(libbuf));
	i = printf("|%d|%i|%d|%u|%x|%p|%s|%s|\n",0,INT_MIN,INT_MAX,index,UINT_MAX,&index,"hello",s);
	fflush(stdout);
	setvbuf(stdout, ftbuf, _IOFBF, sizeof(ftbuf));
	j = ft_printf("|%d|%i|%d|%u|%x|%p|%s|%s|\n",0,INT_MIN,INT_MAX,index,UINT_MAX,  &index,"hello",s);

	fflush(stdout);
	printf("lib_charcount : %d -- ft_charcount : %d \n",i,j);
	if (strcmp(libbuf,ftbuf) && i == j)
	{
		testsuccess();
		return (1);
	}
	else
	{
		testfailled();
		puts("hints-> ???");
		return (0);
	}
	return (0);
}

int main(void)
{
	int i;
	int res;

	res = 0;
	i = 0;
	i += teststart(strdup("basic test"),i + 1);
	res += basictest();
	i += teststart(strdup("c test"),i + 1);
	res += ctest();
	i += teststart(strdup("d test"),i + 1);
	res += dtest();
	i += teststart(strdup("x test"),i + 1);
	res += xtest();
	i += teststart(strdup("X test"),i + 1);
	res += Xtest();
	i += teststart(strdup("i test"),i + 1);
	res += itest();
	i += teststart(strdup("s test"),i + 1);
	res += stest();
	i += teststart(strdup("p test"),i + 1);
	res += ptest();
	i += teststart(strdup("u test"),i + 1);
	res += utest();
	i += teststart(strdup("%% test"),i + 1);
	res += escapetest();
	i += teststart(strdup("discord test"),i + 1);
	res += discordtest();
	puts("\n\n");
	puts("\x1b[32m");
	puts("TEST RESULT\n");
	printf("%d / %d\n",i,res);
	if (res == i)
		puts("hard test clear");
	puts("\x1b[39m");
}
