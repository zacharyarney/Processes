// Write a program that opens the text.txt file (with the `fopen()` library
// call) located in this directory and then calls `fork()` to create a new
// process. Can both the child and parent access the file descriptor returned
// by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// This code gets a segmentation fault 11 and doesn't write in the file
// I'm not totally sure what's causing the error
// seg fault: 11 suggests I'm trying to write info somewhere I don't
// have access to but I'm not writing to memory
// tried with different fopen modes too with no success...
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
