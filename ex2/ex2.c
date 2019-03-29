// Write a program that opens the text.txt file (with the `fopen()` library
// call) located in this directory and then calls `fork()` to create a new
// process. Can both the child and parent access the file descriptor returned
// by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // create file pointer
    FILE *fp;
    // open file
    fp = fopen("text.txt", "w");
    fork();
    // write to file
    fprintf(fp, "Maybe we're writing this twice?\n");
    // close file
    fclose(fp);
    
    return 0;
}
