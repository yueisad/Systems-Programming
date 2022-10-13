//Nonrecursive Fibonacci

#include<stdio.h>

unsigned long long fibonacci(unsigned int);

int main() {
  long long result;
  long long number;
  
  printf("Enter an integer: ");
  scanf("%llu", &number);
  
  result = fibonacci(number);
  printf("Fibonacci(%llu) = %llu\n\n", number, result);
} //end main


//fibonacci nonrecursively calculates nth Fibonacci number
unsigned long long fibonacci(unsigned int n) {

  unsigned int fib0 = 0;  
  //after iteration, holds fib(i - 1), initially fib(0) = 0
  
  unsigned int fib1 = 1; 
  //after iteration, holds fib(i), initially fib(1) = 1

  unsigned int temp;
  //temporary holder for updating fib0 and fib1

  if (n == 0)  //special case
     return 0;

  //loop until nth number reached
  for (unsigned int i = 2; i <= n; ++i) {
      //note at this point:
      //fib0 = fib(i - 2)
      //fib1 = fib(i - 1)

      temp = fib1;      //temporarily hold fib(i - 1)

      //update fib1 to hold fib(i), fib(i) = fib(i - 1) + fib(i - 2)
      fib1 = fib0 + fib1;
      fib0 = temp;              //update fib0 to hold fib(i - 1)

      //note at this point:
      //fib0 = fib(i - 1)
      //fib1 = fib(i)
  }  //end for

  return fib1;
} //end function
