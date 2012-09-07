#include <stdio.h>

int main(int argc, char * argv[])
{
  //char *s1 = "Hello";
  char s1[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
  char *s2 = "World";
  char *s3 = "\n";

  char *list[3] = { s1, s2, s3 };
  int i=0;
  //list[0] = s1;
  //list[1] = s2;
  //list[2] = s3;

  printf ("%p\n", s1);
  printf ("%p\n", list);
  printf ("%ld\n", (long)s1 - (long)list);
  printf ("%c\n", (int)list[0]);
  printf ("%d\n", i);

  return 0;
}
