#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#define FILE_NAME	"temp.c"

int
main(int argc, char **argv) {
	int fd = open(argv[1], O_RDONLY); 
	if (fd < 0) {
		perror("open failed ");
		return 0;
	}
	if (opendir(argv[1]) != NULL) {
		printf("Sorry, This is a directory\n");
		return 0;
	}
	printf("The file %s's content is:\n", argv[1]);
	char buf[1024];
	int n ;
	while ((n = read(fd, buf, sizeof buf - 1)) != 0) {
		buf[n] = 0;
		printf("%s", (char *)buf);
	}
	return 0;
}

/**
develon@ubuntu:~/github/UCUsage$ ./a.out /
Sorry, This is a directory
develon@ubuntu:~/github/UCUsage$ ./a.out open.c
The file open.c's content is:
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#define FILE_NAME       "temp.c"

int
main(int argc, char **argv) {
        int fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
                perror("open failed ");
                return 0;
        }
        if (opendir(argv[1]) != NULL) {
                printf("Sorry, This is a directory\n");
                return 0;
        }
        printf("The file %s's content is:\n", argv[1]);
        char buf[1024];
        int n ;
        while ((n = read(fd, buf, sizeof buf - 1)) != 0) {
                buf[n] = 0;
                printf("%s", (char *)buf);
        }
        return 0;
}

*/
