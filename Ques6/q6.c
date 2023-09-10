#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
int i;
char buf1[1024];
    i=read(STDIN_FILENO, buf1, sizeof(buf1));
    printf("%d",i);
    write(STDOUT_FILENO, buf1, i);
    return 0;
}
