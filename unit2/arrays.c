#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s ...\n", progname);
    exit(1);
}

int main(int argc, char *argv[])
{
  progname = argv[0];
  char *s = "Hello, world\n";
  int i;
  int len;
  
  for (i = strlen(s) - 1; i >= 0; i--) {
    printf("s[%d]='%c'\n", i, s[i]);
  }
  
  return 0;
}
