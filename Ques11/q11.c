#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
    char *pathname="/home/gsouvik/Documents/Ques11/abc.txt";
    int fd = open(pathname, O_RDWR);
    int d=dup(fd);
    int d2=dup2(fd,6);
    int d3=fcntl(fd,F_DUPFD,5);
    write(fd,"Sunday\n",7);
    write(d,"Monday\n",7);
    write(d2,"Tuesday\n",8);
    write(d3,"Wednesday",9);
    printf("%d",fd);
    printf("%d",d);
    printf("%d",d2);
    printf("%d",d3);
    return 0;
}
