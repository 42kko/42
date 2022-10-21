#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int i;
	int fd;
	char *buf;

	buf = (char *)malloc(sizeof(char) * 4);
	buf[3] = 0;
	fd = open("test.txt", O_RDONLY);
	i = read(fd, buf, 3);
	printf("%d\n", i);
	return 0;
}