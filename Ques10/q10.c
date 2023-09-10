#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
    int r=0;
    char *pathname="/home/gsouvik/Documents/Ques10/abc.txt";
    int fd = open(pathname, O_RDWR | O_CREAT);
    write(fd, "How are you?", 12);
    r=lseek(fd,10,SEEK_CUR);
    write(fd, "I am fine, Thank You", 20);
    printf("%d",r);
    return 0;
}
