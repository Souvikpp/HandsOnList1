#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
   char *pathname= "/home/gsouvik/Documents/Ques17/AvailableT.txt"; int i;
   int fd = open(pathname, O_RDWR);
   struct flock fl;
   fl.l_type = F_WRLCK;
   fl.l_whence = SEEK_SET;
   fl.l_start = 0;
   fl.l_len = 0;
   fl.l_pid = getpid();
   fcntl(fd, F_SETLKW, &fl);
   
   char buf[1024];
   while(1)
   {
   i=read(fd,buf,sizeof(buf));
   if(i==0)
   break;
   }
   int j=atoi(buf);
   j=j+1;
   char buf2[100];
   sprintf(buf2,"%d",j);
   lseek(fd,0,SEEK_SET);
   write(fd, buf2, strlen(buf2));
   fl.l_type=F_UNLCK;
   fcntl(fd,F_SETLK,&fl);
   printf("New ticket number is %d",j);
   close(fd);
   return 0;
}
