#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sched.h>

int main() {
int maxF = sched_get_priority_max(SCHED_FIFO);
printf("Maximum priority for FIFO %d \n",maxF);
int minF = sched_get_priority_min(SCHED_FIFO);
printf("Minimum priority for FIFO %d \n",minF);

int maxR = sched_get_priority_max(SCHED_RR);
printf("Maximum priority for RR %d \n",maxR);
int minR = sched_get_priority_min(SCHED_RR);
printf("Minimum priority for RR %d \n",minR);
return 0;
}
