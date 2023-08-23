#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"lg:s", "dfl", NULL}; // Command and its arguments

    // Execute the "ls dl" command
    int pid = fork();
    if (pid == 0)
    {
    if (execvp(args[0], args) == -1) {
        perror("execvp");
        return 1;
    }
    

    // This code will only be reached if execvp fails
    printf("Execution failed\n");
    }
    return 1;
}

