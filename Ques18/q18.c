#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
   printf("Enter Record number\n");
   char r_no;
   scanf("%c",&r_no);
   if(!(r_no=='1'||r_no=='2'||r_no=='3'))
   printf("Record does not exist\n");
   else
   {
   int fd = open("Records.txt", O_RDWR);
   char buf1[1024];
   read(fd,buf1,sizeof(buf1));
   int i=0;
   while(buf1[i]!='\0')
   {
   if(r_no=='1'&&buf1[i]=='\n')
   break;
   else if(buf1[i]=='\n'&&buf1[i+1]==r_no)
   break;
   i++;
   }
   int k=i+1;
   int j=k;
   if(r_no=='3')
   {
   while(buf1[k+1]!='\0')
   k++;
   }
   else if(r_no=='1')
   j=1;
   else
   {
   while(buf1[k]!='\n')
   k++;
   }
   int r_len=k-j;
   //printf("%d",r_len);
   if(r_no=='1')
   j=0; int status;
   
   printf("Enter Lock Type:\n");
   printf("Enter 1 for Write Lock\n");
   printf("Enter 2 for Read Lock\n");
   
   int choice;
   
   scanf("%d",&choice);
   
   if(choice==1)
   {
   struct flock fl;
   fl.l_type = F_WRLCK;
   fl.l_whence = SEEK_SET;
   fl.l_start = j;
   fl.l_len = r_len;
   fl.l_pid = getpid();
   status=fcntl(fd, F_SETLKW, &fl);
   if(status==-1)
   printf("Could not set lock\n");
   else
   printf("Record Locked for Writing\n");
   }
   else if(choice==2)
   {
   struct flock fl;
   fl.l_type = F_RDLCK;
   fl.l_whence = SEEK_SET;
   fl.l_start = j;
   fl.l_len = r_len;
   fl.l_pid = getpid();
   status=fcntl(fd, F_SETLKW, &fl);
   if(status==-1)
   printf("Could not set lock\n");
   else
   printf("Record Locked for Reading\n");
   }
   else
   printf("Wrong choice entered\n");
   
   close(fd);
   }
   return 0;
}
