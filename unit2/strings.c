#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE	256

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s <string1> <string2>\n", progname);
    exit(1);
}

int main(int argc, char *argv[])
{
  progname = argv[0];
  char *s1 = argv[1], *s2 = argv[2];
  char buffer[BUFFER_SIZE];
  int remaining;

  if (argc < 3) {
    usage();
  }

  // String length
  printf("Combined length: %d\n", strlen(s1) + strlen(s2));

  // Compare strings
  if (strcmp(s1, s2) == 0) {
    printf("Matched!\n");
  }

  // Copy strings (safely)
  strncpy(buffer, s1, sizeof(buffer));
  printf("Buffer content 1: %s\n", buffer);

  // Concatenate strings (safely)
  remaining = sizeof(buffer) - strlen(buffer); 
  strncat(buffer, " ", remaining);
  remaining = sizeof(buffer) - strlen(buffer); 
  strncat(buffer, s2, remaining);
  printf("Buffer content 2: %s\n", buffer);

  // Search strings for characters (leftmost and rightmost)

  /*
   * { 'a', 'b', 'c', 'c', 'd', 'e', 'f' }
   */
  if (index(s1, s2[0]) != NULL) {
    printf("Found!\n");
  }

  // Search strings for other strings
  if (strstr(s1, s2) != NULL) {
    printf("Found!\n");
  }

  int start = strlen("abcdef") - 1;
  int i;
  for (i = start; i >= 0; i--) {
  }

  return 0;
}
