#include <stdio.h>
#include <dirent.h>

int
main(int argc, char **argv) {
	for (int i = 1; i < argc; i ++ ) {
		DIR *dir = opendir(argv[i]);
		if (dir == NULL) {
			perror("Can't open directory ");
			return 0;
		}
		printf("%s:\n", argv[i]);
		struct dirent *fp;
		while ((fp = readdir(dir)) != NULL) {
			printf("%s\t", fp->d_name);
		}
		puts("");
	}
	return 0;
}

/**
develon@Topmain:~/github/UCUsage$ a.out /
/:
media   dev     proc    snap    vmlinuz.old     initrd.img.old  tmp     var     lib64   usr     sys     bin     mnt sbin     ..      run     boot    lib32   srv     lib     home    etc     libx32  root    .       lost+found      opt
develon@Topmain:~/github/UCUsage$

*/
