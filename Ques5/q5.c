#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	//int fd;
	mode_t mode = S_IWUSR;
        creat("/home/gsouvik/Documents/Ques5/file1", mode);
        creat("/home/gsouvik/Documents/Ques5/file2", mode);
        creat("/home/gsouvik/Documents/Ques5/file3", mode);
        creat("/home/gsouvik/Documents/Ques5/file4", mode);
        creat("/home/gsouvik/Documents/Ques5/file5", mode);
		printf("fd = %d\n", getpid());
        for(;;);
	return 0;
}
