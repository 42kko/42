#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av, char **envp)
{
	// int fd[2];
	char buffer[100];
	
	// pipe(fd);
	char *cat = "/bin/ls";
	char *cat_cmd[3];
	cat_cmd[0] = "ls";
	cat_cmd[1] = 0;
	cat_cmd[2] = 0;

	int fd = open(av[1], O_RDONLY);
	dup2(fd, 0);
	// int fd2 = open(av[2], O_CREAT, O_RDWR, O_TRUNC);
	// dup2(fd2, 1);
	execve(cat, cat_cmd,envp);
	// close(fd);
	// close(fd2);
	// printf("%s\n", cat);
	// int pid = fork();
	// if(pid == 0)
	// {
	// 	dup2(fd[1], 1);
	// 	close(fd[0]);
	// 	execve(cat, cat_cmd, envp);
	// }
	// close(fd[1]);
	// read(fd[0], buffer, 100);
	// puts(buffer);
}