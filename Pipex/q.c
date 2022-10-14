#include <unistd.h>
#include <stdio.h>

int main()
{
	int pid = fork();
	int x = 0;
	if (pid == 0)
	{
		x = 1;
		printf("pid : %d, %d\n", getpid(), x);
		pid = fork();
		if (pid == 0)
		{
			printf("hi\n");
		}
	}
	else
	{
		x = 2;
		printf("pid : %d, ppid : %d, %d\n", getpid(), pid, x);
	}
}