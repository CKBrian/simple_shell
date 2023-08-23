#include <stdio.h>
#include <unistd.h>

int main() {
    if (isatty(STDIN_FILENO)) {
        printf("Input is coming from a terminal\n");
    } else {
        printf("Input is redirected from a file or pipe\n");
    }

    if (isatty(STDOUT_FILENO)) {
        printf("Output is going to a terminal\n");
    } else {
        printf("Output is redirected to a file or pipe\n");
    }

    return 0;
}

