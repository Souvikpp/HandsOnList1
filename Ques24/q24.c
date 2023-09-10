#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
pid_t pid=fork();
if(pid==0)
{
sleep(5);
printf("Hello I am Child! My PID is %d \n",getpid());
printf("My Parent's PID is %d \n",getppid());
}
else
{
printf("Hello I am Parent! My PID is %d \n",getpid());
printf("My child's PID is %d \n",pid);
}
return 0;
}
