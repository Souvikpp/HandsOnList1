#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
pid_t pid=fork();
if(pid==0)
printf("hello\n");
else
{
pid_t c=wait(0);
printf("%d\n",c);
printf("%d\n",getpid());
}
printf("hello2\n");
return 0;
}
