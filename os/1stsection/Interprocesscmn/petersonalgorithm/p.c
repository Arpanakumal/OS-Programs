#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#define FALSE 0
#define TRUE 1
#define N 2
void *
thread1f(void *arg);
void *thread2f(void *arg);
void enter_region(int);
void leave_region(int);
int interested[N];
int turn;
int main()
{
    pthread_t thid1;
    pthread_t thid2;
    pthread_create(&thid1, NULL, &thread1f, NULL);
    pthread_create(&thid2, NULL, &thread2f, NULL);
    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    return 0;
}
void *thread1f(void *arg)
{
    int a = 0;
    enter_region(0);
    while (a++ < 20000)
    {
        fputc('b', stderr);
    }
    leave_region(0);
}
void *thread2f(void *arg)
{
    int b = 0;
    enter_region(1);
    while (b++ < 20000)
    {
        fputc('a', stderr);
    }
    leave_region(1);
}
void enter_region(int process)
{
    int other;
    other = 1 - process;
    interested[process] = TRUE;
    turn = process;
    while (turn == process && interested[other] == TRUE)
        ;
}
void leave_region(int process)
{
    interested[process] = FALSE;
}
