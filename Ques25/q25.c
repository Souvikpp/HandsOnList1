#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
int status;
pid_t p1=fork();

if(p1==0)
printf("I am Child1\n");
else
{
pid_t p2=fork();
if(p2==0)
printf("I am Child2\n");
else
{
pid_t p3=fork();
if(p3==0)
{
sleep(10);
printf("I am Child3\n");
}
else
{
waitpid(p3,&status,0);
printf("I am Parent\n");
}
}
}
return 0;
}
