#include <stdio.h>

//this function will save the variable value
int enterNum(void)
{
  int e;    
  scanf("%d", &e);
  return e;
}

void printNum(int x)
{
  printf("\n The absolute value of the number is %d.\n\n", x);
}

int main(void) {
  int x;
  printf("\n This program will receive an entire number (Int) and return its absolute value.\n > Please enter a number: ");
    x=enterNum();
      if (x>=0)
      {
        printNum(x);
      }
      else
      {
        x*=-1;
        printNum(x);
      }
  return 0;
}