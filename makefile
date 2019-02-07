targets := *.c

bin/%: %.c
	-$(CC) $^ -o $@ -lpthread

makefile: bin bin/gnu_get_libc_version bin/opendir bin/pthread_create bin/open \
	bin/pthread_cancel
	@echo OK!

bin:
	mkdir bin

.PHONY: clean
clean:
	-rm -rf bin
