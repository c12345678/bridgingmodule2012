/*
 * The name of an array is a pointer to the first element in that array
 */

#include <stdio.h>

int main()
{
  char carray[] = { 'A', 'B', 'C' };

  printf("%p\n", carray);
  printf("%p\n", &carray[0]);

  return 0;
}
