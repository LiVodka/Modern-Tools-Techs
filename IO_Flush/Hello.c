#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int use_fflush = 0;
	int use_newline = 0;
	int i = 1;

	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "flush") == 0) {
			use_fflush = 1;
		} else if (strcmp(argv[i], "newline") == 0) {
			use_newline = 1;
		}
	}

	if (use_newline == 1) {
		printf("hello, world!\n");
        	printf("hello, man!\n");
	} else {
		printf("hello, world!");
		printf("hello, man!");
	}

	if (use_fflush == 1) {
		fflush(stdout);
	}

	sleep(5);

	return 0;
}
