#include <stdio.h>

int main(int argc, char *argv[])
{
  int num1, num2;

  printf("Number 1: ");
  scanf("%d", &num1);

  printf("Number 2: ");
  scanf("%d", &num2);

  printf("Sum: %d + %d = %d\n", num1, num2, num1 + num2);
  
  return 0;
}
