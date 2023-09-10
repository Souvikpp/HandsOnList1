#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
char **ep;
for(ep=environ;*ep!=NULL;ep++)
puts(*ep);
return 0;
}
