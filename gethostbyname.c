#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int
main(int argc, char **argv) {
	for (int i = 1; i < argc; i ++ ) {
		printf("%s:\t\t", argv[i]);
		struct hostent *ent = gethostbyname(argv[i]);
		if (ent == NULL) {
			puts("Unknown");
			continue;
		}
		char buf[INET_ADDRSTRLEN];
		printf("%s\n", inet_ntop(AF_INET, (struct in_addr *)ent->h_addr,
			buf, sizeof buf));
	}
	return 0;
}
