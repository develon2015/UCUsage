#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dlfcn.h>

int
main(int argc, char **argv) {
	if (argc < 3) {
		printf("%s <library> <symbol>\n", argv[0]);
		return 1;
	}
	void *dll = dlopen(argv[1], RTLD_NOW); // 立即解析符号
	if (dll == NULL) {
		printf("[E] Unable load the library: (%s)\n", dlerror());
		printf("[I] Try existed symbol\n");
	}
	void (*onCreate)() = dlsym(dll, argv[2]);
	if (onCreate == NULL) {
		printf("[E] Unable find the symbol: (%s)\n", dlerror());
		return 1;
	}
	onCreate();
	dlclose(dll);
	return 0;
}

int
foo(int a) {
	printf("a -> %d\n", a);
	return a;
}

/*
// libtest.c
// 编译为共享库libtest.so, 提供以下函数, 以供测试
// void onCreate()

#include <stdio.h>

void
onCreate() {
	printf("共享库libtest.so已成功加载\n");
}
*/

/**
d@MyServer:~/github/UCUsage/bin$ dlopen /lib/x86_64-linux-gnu/libc.so.6 abort
Aborted
d@MyServer:~/github/UCUsage/bin$ dlopen ./dlopen foo
a -> 1184754024
d@MyServer:~/github/UCUsage/bin$ dlopen ./libtest.so onCreate
共享库libtest.so已成功加载
d@MyServer:~/github/UCUsage/bin$ dlopen nofile abort
[E] Unable load the library
[I] Try existed symbol
Aborted

*/
