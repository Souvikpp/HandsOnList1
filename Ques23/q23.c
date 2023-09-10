#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
pid_t pid=fork();
if(pid>0)
sleep(300);
else
exit(0);
return 0;
}
