#include <stdio.h>
#include <gnu/libc-version.h>

int
main(int argc, char **argv) {
	printf("The glibc version is %s\n", gnu_get_libc_version());
	return 0;
}

/*
develon@Topmain:~/github/UCUsage$ a.out
The glibc version is 2.23

*/
