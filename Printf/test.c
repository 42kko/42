#include <stdio.h>
#include <string.h>

int main()
{
	char *s = "abc";
	int i = 105334;
	int len = printf ("%p\n", i);
	printf("%d\n", len);
}