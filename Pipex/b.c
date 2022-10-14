#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av, char **envp)
{
	int fd[2];
	(void)av;
	int i = -1;
	while (++i < 15) {
		printf("envp[%d] = %s\n", i, envp[i]);
	}


}

// grep - > /bin

// /usr/local/bin + "/" + "grep" -> /usr/local/bin/grep -> access(path, ) -> true ->


// awk ' { print } '
// [awk] ['] [{print}] [']

// cmd_split = [grep] [a1]
// infile open

// dup2 -> 
// execve(path, cmd_split, envp)  -> 1 ㅌㅓ미널 출출력력

// grep의 출력값을 파이프에 담아서

// [0|1]

// execve