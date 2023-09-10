#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
extern int errno;
  
int main()
{
    char *pathname="/home/gsouvik/Documents/Ques4/abc.txt";
    int fd = open(pathname, O_RDWR, O_EXCL);
  
    if (fd == -1)
    printf("Error Number % d\n", errno);
    else
    printf("fd = %d\n", fd);
    
    return 0;
}
