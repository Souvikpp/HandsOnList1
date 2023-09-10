#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd;
	mode_t mode = S_IWUSR;
	char *pathname="/home/gsouvik/Documents/Ques27/file.txt";
		fd=creat(pathname, mode);
		write(fd,"File Created",12);
		printf("fd = %d\n", fd);
	return 0;
}
