#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
   //char *pathname="/home/gsouvik/Documents/Ques16/def.txt";
   int fd = open("def.txt", O_RDWR);
   struct flock fl;
   fl.l_type = F_WRLCK;
   fl.l_whence = SEEK_SET;
   fl.l_start = 0;
   fl.l_len = 0;
   fl.l_pid = getpid();
   int i=fcntl(fd, F_SETLKW, &fl);
   if(i==-1)
   printf("Unable to acquire Write Lock");
   else
   printf("Acquired Write Lock");
   
   sleep(10);
   
   fl.l_type=F_UNLCK;
   int j=fcntl(fd, F_SETLK, &fl);
   if(j==-1)
   printf("File unable to unlock");
   else
   printf("File unlocked");
   
   sleep(10);
   
   fl.l_type=F_RDLCK;
   int k=fcntl(fd,F_SETLK,&fl);
   if(k==-1)
   printf("Unable to acquire Read Lock");
   else
   printf("Acquired Read Lock");
   
   sleep(10);
   
   fl.l_type=F_UNLCK;
   int l=fcntl(fd, F_SETLK, &fl);
   if(l==-1)
   printf("File unable to unlock");
   else
   printf("File unlocked");
   
   close(fd);
   return 0;
}
