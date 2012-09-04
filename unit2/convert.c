#include <stdio.h>
#include <stdlib.h>

static char *progname;

static float c2f(float c)
{
  return (c * 9.0 / 5.0) + 32.0;
}

static float f2c(float f)
{
  return (f - 32.0) / 1.8;
}

static void usage(void)
{
    fprintf(stderr, "Usage: %s c|f <float>\n", progname);
    exit(1);
}

int main(int argc, char *argv[])
{
  char *flag = argv[1];
  char *tempString = argv[2];
  float celcius, farenheit;

  progname = argv[0];
  if (argc < 3) {
    usage();
  }

  if (flag[0] == 'c') {
    if (sscanf(tempString, "%f", &farenheit) != 1) {
      usage();
    }
    printf("%.2f\n", f2c(farenheit));
  } else if (flag[0] == 'f') {
    if (sscanf(tempString, "%f", &celcius) != 1) {
      usage();
    }
    printf("%.2f\n", c2f(celcius));
  } else {
    usage();
  }
  
  return 0;
}
