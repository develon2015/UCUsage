#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_NAME	"temp.c"

int
main(int argc, char **argv) {
	int fd = open(argv[1], O_RDONLY); 
	if (fd < 0) {
		perror("open failed ");
		return 0;
	}
	char buf[1024];
	int n ;
	while ((n = read(fd, buf, sizeof buf)) != 0) {
		buf[n] = 0;
		printf("%s", (char *)buf);
	}
	return 0;
}
