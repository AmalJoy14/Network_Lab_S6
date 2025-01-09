#include <stdio.h>
#include <unistd.h>

void main() {
    int id = fork();
    
    if (id == 0) {
        printf("Child process is running\n");
        printf("Process id : %d\n", getpid());
        printf("Parent id : %d\n\n", getppid());
    }
    else if (id > 0) {
        wait(NULL);
        printf("Parent process is running\n");
        printf("Process id : %d\n\n", getpid());
    }
    else {
        printf("Fork Failed\n");
    }
}


// OUTPUT :
// Child process is running
// Process id : 209661
// Parent id : 209660

// Parent process is running
// Process id : 209660
