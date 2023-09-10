#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sched.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int main() {

pid_t sid;
pid_t pid=fork(); 

if(pid>0)
exit(0);

sid=setsid();

close(0);
close(1);
close(2);

struct tm st;
st.tm_hour=18;
//st.tm_min=18;

time_t now;

while(1)
{
time(&now);
struct tm* cur_time=localtime(&now);
if(cur_time->tm_hour==st.tm_hour)
system("bash Script.sh");

sleep(86400);
}
return 0;
}
