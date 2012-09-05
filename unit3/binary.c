#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s <binary>\n", progname);
    exit(1);
}

int powerof2(int n)
{
  return (1 << n);
}

char *b2d(char *in, char *out, int size)
{
  int len = strlen(in);
  int i;
  int acc = 0;
  char c;

  //    0    1    2    3
  // { '1', '1', '0', '1' }
  //    3    2    1    0
  
  for (i = 0; i < len; i++) {
    c = in[i];
    if (c != '0' && c != '1') {
      usage();
    }
    if (c == '1') {
      acc += powerof2(len - 1 - i);
    }
  }
  sprintf(out, "%d", acc);

  return out;
}

int main(int argc, char *argv[])
{
  char buffer[32];
  char *binString, *decString;

  progname = argv[0];
  if (argc < 2) {
    usage();
  }

  binString = argv[1];
  decString = b2d(binString, buffer, sizeof(buffer));
  printf("0b%s => %s\n", binString, decString);

  return 0;
}
