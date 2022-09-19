#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "ft_isalnum.c"
#include "ft_isalpha.c"
#include "ft_isascii.c"
#include "ft_isdigit.c"
#include "ft_isprint.c"
#include "ft_memset.c"
#include "ft_strlen.c"
#include "ft_memcpy.c"
#include "ft_bzero.c"
#include "ft_memmove.c"
#include "ft_strncmp.c"
#include "ft_memchr.c"
#include "ft_memcmp.c"
#include "ft_strnstr.c"
#include "ft_atoi.c"
#include "ft_split.c"
#include "ft_substr.c"
#include "ft_strjoin.c"
#include "ft_itoa.c"
#include "ft_strtrim.c"
#include "ft_strchr.c"
#include "ft_strmapi.c"
#include "ft_putchar_fd.c"
#include "ft_putstr_fd.c"
#include "ft_putnbr_fd.c"
#include "ft_strdup.c"
#include "ft_strlcpy.c"

char f(unsigned int i, char c)
{
	char str;
	str = c + 1;
	return (str);
}

int	main()
{
	printf("====isalpha====\n");

	{
		printf("%d : %d\n", isalpha('a'), ft_isalpha('a'));
		printf("%d : %d\n", isalpha('!'), ft_isalpha('!'));
		printf("%d : %d\n", isalpha('A'), ft_isalpha('A'));
		printf("%d : %d\n", isalpha(' '), ft_isalpha(' '));
		printf("%d : %d\n", isalpha('1'), ft_isalpha('1'));
	}

	printf("====isdigit====\n");
	{
		printf("%d : %d\n", isdigit('9'), ft_isdigit('9'));
		printf("%d : %d\n", isdigit('!'), ft_isdigit('!'));
		printf("%d : %d\n", isdigit('A'), ft_isdigit('A'));
		printf("%d : %d\n", isdigit(' '), ft_isdigit(' '));
		printf("%d : %d\n", isdigit('0'), ft_isdigit('0'));

	}
	printf("====isalnum====\n");
	{
		printf("%d : %d\n", isalnum('0'), ft_isalnum('0'));
		printf("%d : %d\n", isalnum('9'), ft_isalnum('9'));
		printf("%d : %d\n", isalnum('a'), ft_isalnum('a'));
		printf("%d : %d\n", isalnum(' '), ft_isalnum(' '));
		printf("%d : %d\n", isalnum('!'), ft_isalnum('!'));
	}

	printf("====isascii====\n");
	{
		printf("%d : %d\n", isascii(127), ft_isascii(127));
		printf("%d : %d\n", isascii(0), ft_isascii(0));
		printf("%d : %d\n", isascii(128), ft_isascii(128));
		printf("%d : %d\n", isascii(214748368), ft_isascii(214748368));
	}

	printf("====isprint====\n");
	{
		printf("%d : %d\n", isprint(30), ft_isprint(30));
		printf("%d : %d\n", isprint(31), ft_isprint(31));
		printf("%d : %d\n", isprint(100), ft_isprint(100));
		printf("%d : %d\n", isprint(126), ft_isprint(126));
		printf("%d : %d\n", isprint(127), ft_isprint(127));
	}

	printf("====isprint====\n");
	{
		char str1[100] = "Hello";
		char str2[11] = "suc ma dic";
		char str3[11] = "kko\0kko";
		printf("%lu : %lu\n", strlen(str1), ft_strlen(str1));
		printf("%lu : %lu\n", strlen(str2), ft_strlen(str2));
		printf("%lu : %lu\n", strlen(str3), ft_strlen(str3));
	}

	printf("====memset====\n");
	{
		char str1[30] = "Hello gaepo";

		printf("%s : %s\n", memset(str1, 'a', 8), ft_memset(str1, 'a', 8));
		printf("%s : %s\n", memset(str1, '5', 20), ft_memset(str1, '5', 20));
	}
	printf("====bzero====\n");
	{

	}

	printf("====memcpy====\n");
	{
	int str1[] =  {11, 280, 300};
	int dst_o[3];
	int	dst_u[3];
	ft_memcpy(dst_u, str1, sizeof(str1));
	memcpy(dst_o, str1, sizeof(int) * 2);
	for(int i = 0; i < 3; i++)
	{
		printf("%d ", dst_o[i]);
	}
	printf("\n");
	for(int i = 0; i < 3; i++)
	{
		printf("%d ", dst_u[i]);
	}
	printf("\n");
	char str2[] =  "Hellowolrdkko!";
	char dst_o1[50];
	char dst_o2[50] = "asdfasdfasdfdsfdd";
	char dst_u2[50] = "asdfasdfasdfdsfdd";
	char dst_u1[50];
	memcpy(dst_o1, str2, sizeof(char) * 9);
	ft_memcpy(dst_u1, str2, sizeof(char) * 9);
	printf("%s : %s\n", dst_o1, dst_u1);
	printf("\n");
	}

	printf("====memcpy====\n");
	{
		char str1[10] = "  tesa";
		char str2[10] = "  tesa";
		memmove(str1, str1 + 2, 4);
		ft_memmove(str2, str2 + 2, 4);
		printf("%s : %s\n", str1, str2);
	}

	printf("====strncmp====\n");
	{
		char str1[] = "BlockDmast";
		char str2[] = "BlockFmast";
		printf("%d : %d\n",strncmp(str1, str2, 5), ft_strncmp(str1, str2, 5));
	}
	printf("====memchr====\n");
	{
		char str1[] = "hellokko";
		printf("%s : %s\n", (char *)memchr(str1, 'k', 5), (char *)ft_memchr(str1, 'k', 5));
		printf("%s : %s\n", (char *)memchr(str1, 'k', 6), (char *)ft_memchr(str1, 'k', 6));
	}
	printf("====memcmp====\n");
	{
		char str1[] = "abcde";
		char str2[] = "abcdd";
		printf("%d : %d\n", memcmp(str1, str2, 5), ft_memcmp(str1, str2, 5));
	}
	printf("====strstr====\n");
	{
		char str1[] = "hellokkkko";
		char str2[] = "kko";
		printf ("%s : %s\n", strnstr(str1, str2, 10), ft_strnstr(str1, str2, 102));
	}
	printf("====atoi====\n");
	{
		char str1[] = "       -242";
		char str2[] = "27670116110564327425";
		printf("%d : %d\n", atoi(str1), ft_atoi(str1));
		printf("%d : %d\n", atoi(str2), ft_atoi(str2));
	}
	printf("====substr====\n");
	{
		char str1[] = "hello im kko";
		char *str2;
		str2 = ft_substr(str1, 4, 4);
	    printf("%s\n", str2);
	}
	printf("====strjoin====\n");
	{
		char str1[] = "hi";
		char str2[] = " hello";
		char *s;

		s = ft_strjoin(str1, str2);
		printf("%s\n", s);
	}
	printf("====strtrim====\n");
	{
		char s1[] = "  im kko hi  ";
		char set[] = " ";
		char *s2;
		s2 = ft_strtrim(s1, set);
		printf("%s\n", s2);
	}

	printf("====split====\n");
	{
		char str1[] = "hi im   kko";
		char **s;
		s = ft_split(str1, ' ');
		printf("%s\n",s[2]);
	}
	printf("====itoa====\n");
	{
		int	n;
		char *s;
		n = -88615;
		s = ft_itoa(n);
		printf("%s\n", s);
	}
	printf("========\n");
	{
		char str1[] = "abc";
		char *str2;
		str2 = ft_strmapi(str1, *f);
		printf("%s\n", str2);
	}
	printf("====putchar_fd====\n");
	{
		int	i = 1;
		char c = 'a';
		ft_putchar_fd(c, i);
	}
	printf("====putstr_fd====\n");
	{
		char str1[] = "abcdf\n";
		int	i = 1;
		ft_putstr_fd(str1,i);
	}
	printf("====putnbr_fd====\n");
	{
		int fd = 1;
		int i  = 15453438;
		ft_putnbr_fd(i, fd);
	}
	printf("====ft_strdup====\n");
	{
	char *s;
	s = ft_strdup("zz");
	printf("%s\n",s);
	}

	return 0;
}
