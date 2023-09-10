#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
int which=PRIO_PROCESS;
int p=getpid();
int priority=getpriority(which,p);
printf("%d",priority);
int priority2=nice(5);
printf("%d",priority2);
return 0;
}
