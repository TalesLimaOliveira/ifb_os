#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = fork();

    if (pid < 0){
        perror("Fork failed");
        return 1;
    }
    
    // Child process
    if (pid == 0) {
        printf("Child process:\n\tPID = %d, PPID = %d\n", getpid(), getppid());
        
        char *args[] = {"ls", "-l", NULL}; // Command and arguments
        execv("/bin/ls", args); // Execute ls command

        perror("execv failed"); // If execv fails
        return 1; // Exit child process
    }


    // Parent process
    int status;
    printf("Parent process:\n\tPID = %d, waiting for child PID = %d\n", getpid(), pid);
    
    pid_t waited_pid = wait(&status);
    
    if (waited_pid == pid) {
        printf("Child with PID %d terminated.\n", waited_pid);
        if (WIFEXITED(status)) {
            printf("Child exited with status %d.\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
