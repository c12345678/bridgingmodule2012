/*
 * Integer scalar types
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  long long number = 123;

  printf("Size in memory: %d bytes\n", sizeof(number));
  printf("Value of number: %d\n", number);

  return 0;
}

