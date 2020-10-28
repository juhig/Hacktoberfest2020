// Code by : Prashant Agheda (https://github.com/prashant-agheda)

// Program for Factorial of a Number using Dart Programming Language

void main()
{
  int number = 5;
  int fact = 1;
  int i;
  
  for(i = number; i >= 1; i--)
  {
    fact = fact * i;
  }
  
  print("Factorial of $number is $fact");
}
