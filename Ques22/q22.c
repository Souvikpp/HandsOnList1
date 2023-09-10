#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
int fd=open("abc.txt",O_RDWR);
pid_t pid=fork();
if(pid==0)
write(fd,"Written by child\n",17);
else
write(fd,"Written by parent\n",18);
wait(0);
return 0;
}
