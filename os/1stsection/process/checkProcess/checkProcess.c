#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid;
    printf("\n I am the original process with PID:%d & PPID:%d\n", getpid(), getppid());
    pid = fork();
    if (pid != 0)
        printf("\n I am the parent with PID:%d & PPID:%d\n", getpid(), getppid());
    else
    {
        printf("\n I am the child with PID:%d & PPID:%d\n", getpid(), getppid());
        sleep(8);
        printf("\n I am the child with PID:%d & PPID:%d\n", getpid(), getppid());
    }

    printf("\n PID %d terminates.\n", getpid());
    return 0;
}
