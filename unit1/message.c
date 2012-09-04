#include <stdio.h>
#include <stdlib.h>

/*
 * Program to print messgae passed in on command line
 */

int main(int argc, char *argv[])
{
  char *msg = argv[1];		// Message to print

  if (argc < 2) {
    // Bail if user does't pass in message argument
    fprintf(stderr, "Usage: %s <message>\n", argv[0]);
    exit(1);
  }
  printf("Hello, %s\n", msg);
  return 0;
}

