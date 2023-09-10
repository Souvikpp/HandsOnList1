#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
  
int main()
{
    char *pathname="/home/gsouvik/Documents/Ques12/abc.txt";
    int fd = open(pathname, O_RDWR);
    int res=fcntl(fd,F_GETFL);
    
    printf("%d\n",fd);
    printf("%d\n",res&O_ACCMODE);
    return 0;
}
