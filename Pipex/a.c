#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av, char **envp)
{
        char *arg1="-al";
        char *arg2="/etc";
        char *file = "ls";
        char *argv[]={file,arg1,NULL};
        char *path = "/bin/ls";


        printf("execve호출\n");
        execve(path, argv, NULL);
}