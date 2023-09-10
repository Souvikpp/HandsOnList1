#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
  
int main(int argc, char* argv[])
{
struct stat s;
stat(argv[1], &s);
switch(s.st_mode & S_IFMT)
{
case S_IFREG: printf("Regular File"); break;
case S_IFDIR: printf("Directory"); break;
case S_IFCHR: printf("Character Device"); break;
case S_IFBLK: printf("Block Device"); break;
case S_IFLNK: printf("Symbolic Link"); break;
case S_IFIFO: printf("FIFO or PIPE"); break;
case S_IFSOCK: printf("Socket"); break;
default: printf("Unknown File Type"); break;
}
 return 0;
}
