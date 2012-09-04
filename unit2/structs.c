#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *progname;

struct fraction
{
  int numerator, denominator;
};

static void print(struct fraction f)
{
  printf("%d/%d\n", f.numerator, f.denominator);
}

static int gcd(int a, int b)
{
  int t;
  while (b != 0) {
    t = a; 
    a = b; 
    b = t % b;
  }
  return a < 0 ? -a : a; /* abs(u) */
}

static int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}

static struct fraction scale(struct fraction f)
{
  int g = gcd(f.numerator, f.denominator);
  f.numerator /= g;
  f.denominator /= g;

  return f;
}

static struct fraction add(struct fraction f1, struct fraction f2)
{
  struct fraction r;

  r.denominator = lcm(f1.denominator, f2.denominator);
  f1.numerator = r.denominator / f1.denominator;
  f2.numerator = r.denominator / f2.denominator;
  r.numerator = f1.numerator + f2.numerator;

  return r;
}

static struct fraction sub(struct fraction f1, struct fraction f2)
{
  struct fraction r;

  r.denominator = lcm(f1.denominator, f2.denominator);
  f1.numerator = r.denominator / f1.denominator;
  f2.numerator = r.denominator / f2.denominator;
  r.numerator = f1.numerator - f2.numerator;

  return r;
}

static struct fraction mul(struct fraction f1, struct fraction f2)
{
  struct fraction r;

  r.numerator = f1.numerator * f2.numerator;
  r.denominator = f1.denominator * f2.denominator;

  return scale(r);
}

static struct fraction divide(struct fraction f1, struct fraction f2)
{
  struct fraction r;

  r.numerator = f1.numerator * f2.denominator;
  r.denominator = f1.denominator * f2.numerator;

  return scale(r);
}

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

  struct fraction f1 = {1, 8};
  struct fraction f2 = {3, 4};

  print(divide(f1, f2));

  return 0;
}
