#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char carray[] = "Hello\n";

  //char carray[] = { 'H', 'e', 'l', 'l', 'o', '\n', '\0' };

  printf("Size in memory: %d bytes\n", sizeof(carray));
  printf("Number of characters: %d characters\n", strlen(carray));

  return 0;
}

