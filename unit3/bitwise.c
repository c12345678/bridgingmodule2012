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
    //usage();
  }

  // 0001 1010

  //      16         8          2
  int i = (1 << 4) | (1 << 3) | (1 << 1);

  printf("0x%02x\n", i);

  return 0;
}
