#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

static void usage(void)
{
    fprintf(stderr, "Usage: %s <decimal>\n", progname);
    exit(1);
}

static char *d2b(char *in, char *out, int size)
{
  int dec = atoi(in);
  int i = 0, j;
  char buffer[size];

  while (dec != 0) {
    int q = dec / 2;
    int r = dec % 2;
    buffer[i++] = r + '0';
    dec = q;
  }
  buffer[i] = '\0';

  for (--i, j = 0; i >= 0; i--, j++) {
    out[j] = buffer[i];
  }
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

  decString = argv[1];
  binString = d2b(decString, buffer, sizeof(buffer));
  printf("%s => 0b%s\n", decString, binString);

  return 0;
}
