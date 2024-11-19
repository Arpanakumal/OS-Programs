#include<unistd.h>
#include<stdio.h>
int main(){
    int count;
    count = write(1,"hello\n ",6);
    printf("Total Bytes written: %d\n",count);
    return 0;
}