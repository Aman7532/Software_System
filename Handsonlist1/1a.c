// Aman Agarwal
// MT2024017

// 1. Create the following types of a files using (i) shell command (ii) system call
// a. soft link (symlink system call)

#include <unistd.h>
#include <stdio.h>
int main()
{
  symlink("text1.txt", "hello_link.txt");
  printf("symbolic link created");
  return 0;
}
// OUTPUT
// symbolic link created