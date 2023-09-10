#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sched.h>

int main() {
int f=sched_getscheduler(getpid());
switch(f)
{
case SCHED_OTHER: printf("OTHER\n"); break;
case SCHED_RR: printf("RR\n"); break;
case SCHED_FIFO: printf("FIFO\n"); break;
//case SCHED_BATCH: printf("BATCH"); break;
//case SCHED_IDLE: printf("IDLE"); break;
}
struct sched_param param;
param.sched_priority=5;
sched_setscheduler(getpid(),SCHED_FIFO,&param);

int g=sched_getscheduler(getpid());
switch(g)
{
case SCHED_OTHER: printf("OTHER\n"); break;
case SCHED_RR: printf("RR\n"); break;
case SCHED_FIFO: printf("FIFO\n"); break;
}
sched_setscheduler(getpid(),SCHED_RR,&param);
int h=sched_getscheduler(getpid());
switch(h)
{
case SCHED_OTHER: printf("OTHER\n"); break;
case SCHED_RR: printf("RR\n"); break;
case SCHED_FIFO: printf("FIFO\n"); break;
}
return 0;
}
