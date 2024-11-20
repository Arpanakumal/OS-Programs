#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    int pid;
    pid = fork(); // fork another process
    if (pid < 0)  // error occurred
    {

        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0) // child process
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else // parent process
    {
        // parent will wait for child to complete
        wait(NULL);
        printf("\n Child Complete \n");
        exit(0);
    }
    return 0;
}
