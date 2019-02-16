# 编译到bin目录下
VPATH = bin

%: %.c
	-$(CC) $^ -o bin/$@ -lpthread -ldl

makefile: bin gnu_get_libc_version opendir pthread_create open \
	pthread_cancel dlopen libtest.so
	@echo OK!

bin:
	mkdir bin

.PHONY: clean
clean:
	-rm -rf bin

dlopen: dlopen.c
	$(CC) dlopen.c -o bin/dlopen -ldl -rdynamic # 导出符号
libtest.so: libtest.c
	$(CC) -shared -fPIC libtest.c -o bin/libtest.so

