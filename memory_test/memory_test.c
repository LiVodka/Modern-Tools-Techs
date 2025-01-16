#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KB 1024
#define STEP 4 * KB

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <memory_size_in_KB> <read_or_write>\n", argv[0]);
        return 1;
    }

    long long memory_size = atoll(argv[1]) * KB;
    char operation = argv[2][0];
    char *buffer = (char *)malloc(memory_size);
    if (buffer == NULL) {
        perror("malloc failed");
        return 1;
    }

    long long i;
    int pause_count = 0;
    int pause_threshold = 10000;
    int pause_duration = 100;

    for (i = 0; i < memory_size; i += STEP) {
        if (operation == 'r') {
            char value = buffer[i];
            (void)value;
        } else if (operation == 'w') {
            buffer[i] = 'A';
        }
        pause_count++;
        if (pause_count == pause_threshold) {
            usleep(pause_duration * 1000);
            pause_count = 0;
        }
    }

    free(buffer);
    return 0;
}