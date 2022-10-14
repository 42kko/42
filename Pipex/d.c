#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av, char **envp)
{
	int fd[2];
	char buffer[100];
	
	// char *cat = "/usr/bin/grep";
	char *cat = "/bin/cat";
	char *cat_cmd[3];
	cat_cmd[0] = "- e";
	cat_cmd[1] = 0;
	cat_cmd[2] = 0;

	pipe(fd);
	int pid = fork();
	if(pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		int fd = open(av[1], O_RDONLY);
		dup2(fd, 0);
		execve(cat, cat_cmd, envp);
		close(fd);
	}
	close(fd[1]);
	read(fd[0], buffer, 100);
	puts(buffer);
}