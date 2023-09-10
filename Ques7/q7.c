#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main(int argc, char* argv[])
{
int r=open(argv[1],O_RDONLY);
int w=open(argv[2],O_WRONLY|O_CREAT);
int fd1, i;
char buf1[1024];
while(1)
{
    i=read(r,buf1,sizeof(buf1));
    if(i==0)
    break;
    write(w, buf1, i);
    close(r);
    close(w);
    return 0;
}
}
