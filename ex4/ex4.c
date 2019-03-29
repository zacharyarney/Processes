// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", NULL);
        // p passes the PATH to the new process
        // e passes the whole env to the new process 
        // Seems like with execv() you pass in an array as the second argument
        // with all of the command arguments. This would be good for making
        // the command dynamic if the number of args is unknown.
            // example:
            // char *flags[] = {"ls", "-la", "-R", "-p", NULL};
            // execvp("ls", flags);
    }

    wait(NULL);
    return 0;
}
