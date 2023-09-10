#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
  
int main()
{
char *pathname="/home/gsouvik/Documents/Ques17/AvailableT.txt";
printf("Store a ticket number");
int fd=open(pathname, O_RDWR);
char buf1[1024];
scanf("%s",buf1);
write(fd, buf1, strlen(buf1));
}
