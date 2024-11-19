#include <unistd.h>
int main()
{
    int nread;
    char buff[20];
    nread = read(0, buff, 10);
    write(1, buff, nread);
    return 0;
}