#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
pid_t pid=fork();
if(pid==0)
printf("%d %d\n\n",getpid(),getppid());
else
printf("%d\n",getpid());
wait(0);
return 0;
}
