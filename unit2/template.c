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
  if (argc < 3) {
    usage();
  }

  return 0;
}
