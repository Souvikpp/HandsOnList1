#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	mode_t mode = S_IWUSR;
	char *pathname="/home/gsouvik/Documents/Ques3/file";
		fd=creat(pathname, mode);
		printf("fd = %d\n", fd);
	return 0;
}
