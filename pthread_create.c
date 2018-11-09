#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>

void *
run(void *arg) {
	//pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	//pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	printf("This is a new thread %lx\n", pthread_self());
	for (;;) {
		printf("%s\n", (const char *)arg);
		sleep(1);
	}
	return NULL;
}

void *
run_daemon(void *arg) {
	printf("Daemon started\n");
	sleep(3);
	if (pthread_cancel(*(pthread_t *)arg) != 0) {
		perror("Can't cancel this thread\n");
	}
	void *res;
	pthread_join(*(pthread_t *)arg, &res);
	if (res == PTHREAD_CANCELED)
		printf("Daemon: canceled\n");
	printf("Daemon exit\n");
	return NULL;
}

int
main(int argc, char **argv) {
	char data[] =  "Hello world!";
	pthread_t tid = { 0 };
	pthread_attr_t attr = { 0 };
	if (pthread_create(&tid, (void *)&attr, run, &data) != 0) {
		perror("Can't create thread ");
		return 0;
	}
	pthread_t tid_daemon = { 0 };
	pthread_create(&tid_daemon, &attr, run_daemon, &tid);
	getchar();
	return 0;
}

/**
develon@ubuntu:~/github/UCUsage$ ./a.out
This is a new thread 7f4669909700
Hello world!
Daemon started
Hello world!
Hello world!
Hello world!
Daemon: canceled
Daemon exit

*/
