#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s <src> <target>", progname);
    exit(1);
}

/*
 * "This is a test testing string"
 *            ^    ^
 * strstr-----+    |
 * rstrstr---------+
 */

char *rstrstr(char *src, char *target)
{
  int i;
  int len = strlen(target);

  for (i = strlen(src) - 1 - strlen(target); i >= 0; i--) {
    char *s = &src[i];
    if (strncmp(s, target, len) == 0) {
      return s;
    }
  }

  return NULL;
}

int main(int argc, char *argv[])
{
  progname = argv[0];
  if (argc < 3) {
    usage();
  }

  char *where = rstrstr(argv[1], argv[2]);
  if (where != NULL) {
    printf("Found\n");
  }

  return 0;
}
