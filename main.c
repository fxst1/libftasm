#include "./inc/libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int		bzero_valid(void)
{
	char	buffer[256];
	size_t	i;

	i = 0;
	while (i < 256)
	{
		buffer[i] = 42;
		i++;
	}
	ft_bzero(buffer, 256);
	i = 0;
	while (i < 256)
	{
		if (buffer[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int		strlen_valid(char *str)
{
	return (strlen(str) == ft_strlen(str));
}

static int		strcat_valid(void)
{
	char	buffer[32];

	ft_bzero(buffer, 1);
	ft_strcat(buffer, "Hello");
	ft_strcat(buffer + 5, " ");
	ft_strcat(buffer, "World");
	return (strcmp(buffer, "Hello World") == 0);
}

void			do_test(int (*fct)(void), const char *name)
{
	if ((*fct)())
		printf("%s OK\n", name);
	else
		printf("%s ERROR\n", name);
}

void			do_test_int(int (*fct)(int), const char *name, int value)
{
	if ((*fct)(value))
		printf("%s OK\n", name);
	else
		printf("%s ERROR\n", name);
}

void			do_test_str(int (*fct)(char*), const char *name, char* str)
{
	if ((*fct)(str))
		printf("%s OK\n", name);
	else
		printf("%s ERROR\n", name);
}

#include <ctype.h>

int				main(void)
{
	int			i;

	do_test(&bzero_valid, "bzero");

	printf("\n");

	do_test(&strcat_valid, "strcat");

	printf("\n");

	i = 0;
	while (i < 300)
	{
		if ((!!isalpha(i)) != ft_isalpha(i))
		{
			printf("Error : ft_isalpha : %d - %c (%d %d)\n", i, i, isalpha(i), ft_isalpha(i));
			return (0);
		}
		i++;
	}

	printf("ft_isalpha : OK\n");

	i = 0;
	while (i < 300)
	{
		if ((!!isdigit(i)) != ft_isdigit(i))
		{
			printf("Error : ft_isdigit : %d - %c (%d %d)\n", i, i, isdigit(i), ft_isdigit(i));
			return (0);
		}
		i++;
	}

	printf("ft_isdigit : OK\n");

	do_test_int(&ft_isalnum, "ft_isalnum(A)", 'A');
	do_test_int(&ft_isalnum, "ft_isalnum(a)", 'a');
	do_test_int(&ft_isalnum, "ft_isalnum(b)", 'b');
	do_test_int(&ft_isalnum, "ft_isalnum(_)", '_');
	do_test_int(&ft_isalnum, "ft_isalnum(2)", '2');

	printf("\n");

	do_test_int(&ft_isascii, "ft_isascii(0)", 0);
	do_test_int(&ft_isascii, "ft_isascii(127)", 127);
	do_test_int(&ft_isascii, "ft_isascii(255)", 255);
	do_test_int(&ft_isascii, "ft_isascii(32)", 32);
	do_test_int(&ft_isascii, "ft_isascii(-1)", -1);

	printf("\n");

	do_test_int(&ft_isprint, "ft_isprint(0)", 0);
	do_test_int(&ft_isprint, "ft_isprint( )", ' ');
	do_test_int(&ft_isprint, "ft_isprint(b)", 'b');
	do_test_int(&ft_isprint, "ft_isprint(\\n)", '\n');
	do_test_int(&ft_isprint, "ft_isprint(2)", '2');

	printf("\n");

	do_test_str(&strlen_valid, "ft_strlen(hello world)", "hello world");

	return (0);
}
