#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
  
int main()
{
    char *pathname="/home/gsouvik/Documents/Ques9/abc.txt";
    struct stat s;
    stat(pathname, &s);
    printf("%ld\n", s.st_ino);
    printf("%ld\n", s.st_nlink);
    printf("%d\n", s.st_uid);
    printf("%d\n", s.st_gid);
    printf("%ld\n", s.st_size);
    printf("%ld\n", s.st_blksize);
    printf("%ld\n", s.st_blocks);
    printf("%s\n", ctime(&(s.st_atime)));
    printf("%s\n", ctime(&(s.st_mtime)));
    printf("%s\n", ctime(&(s.st_ctime)));
    return 0;
}
