#include <stdio.h>
#include <string.h>

#define s1  "c="
#define s2  "c-"
#define s3  "dz="
#define s4  "d-"
#define s5  "lj"
#define s6  "nj"
#define s7  "s="
#define s8  "z="


int	search(char *str, char *s)
{
	int	i;
	int	j;
	int ret;

	ret = 0;
	j = 0;
	while(str[j])
	{
		i = 0;
		while (str[j + i] == s[i] && s[i] != 0)
			i++;
		if (s[i] == 0)
		{
			ret++;
		}
		j++;
	}
	return (ret);
}

int	alpha(char *str)
{
	int len;
	int i;

	len = 0;
	len += search(str, s1);
	len += search(str, s2);
	len += search(str, s3);
	len += search(str, s4);
	len += search(str, s5);
	len += search(str, s6);
	len += search(str, s7);
	len += search(str, s8);
	return (strlen(str) - len);
}

int main(int ac, char **av)
{
	int i;
	char a[100];

	scanf("%s", a);
	printf("%d", alpha(a));
	return 0;
}