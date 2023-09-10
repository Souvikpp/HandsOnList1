#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
  
int main()
{
int fd1;
char buf1[1024];

    char *pathname="/home/gsouvik/Documents/Ques8/abc.txt";
    fd1 = open(pathname, O_RDONLY);
    read(fd1,buf1,sizeof(buf1));
    char buf2[1024]; int k=0; int j=0;
    while(buf1[k]!='\0')
    {
    if(buf1[k]=='\n')
    {
    buf2[j]='\n';
    write(STDOUT_FILENO, buf2, j+1);
    j=-1;
    }
    else
    buf2[j]=buf1[k];
    j++;
    k++;
    }
    close(fd1);
    return 0;
}
