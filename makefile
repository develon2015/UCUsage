# 编译到bin目录下
VPATH = bin

%: %.c
	-$(CC) $^ -o bin/$@ -lpthread

makefile: bin gnu_get_libc_version opendir pthread_create open \
	pthread_cancel
	@echo OK!

bin:
	mkdir bin

.PHONY: clean
clean:
	-rm -rf bin
