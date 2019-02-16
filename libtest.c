// libtest.c
// 编译为共享库libtest.so, 提供以下函数, 以供测试
// void onCreate()

#include <stdio.h>

void
onCreate() {
	printf("共享库libtest.so已成功加载\n");
}
