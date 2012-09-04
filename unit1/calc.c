/*
 * A simple general purpose calculator demonstrating functions and function dispatch
 */

#include <stdio.h>
#include <stdlib.h>

int add(int n1, int n2)
{
  return n1 + n2;
}

int sub(int n1, int n2)
{
  return n1 - n2;
}

int mul(int n1, int n2)
{
  return n1 * n2;
}

int divide(int n1, int n2)
{
  if (n2 != 0) {
    return n1 / n2;
  } else {
    fprintf(stderr, "Can't divide by zero!\n");
    exit(1);
  }
}

int calc(int n1, char op, int n2)
{
  switch(op) {
  case '+':
    return add(n1, n2);
  case '-':
    return sub(n1, n2);
  case '*':
    return mul(n1, n2);
  case '/':
    return divide(n1, n2);
  default:
    fprintf(stderr, "Unsupported op '%c'\n", op);
    exit(1);
  }
}

int main(int argc, char *argv[])
{
  int num1, num2;
  char op[2];

  printf("Number 1: ");
  scanf("%d", &num1);

  printf("op [+-*/]: ");
  scanf("%s", op);

  printf("Number 2: ");
  scanf("%d", &num2);
  printf("> %d %s %d = %d\n", num1, op, num2, calc(num1, op[0], num2));

  return 0;
}

