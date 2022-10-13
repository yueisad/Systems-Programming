//recursive Fibonacci 

#include<stdio.h>

long fibonacci (long);

int main(void) {
   long long result;
   long number;
   
   printf("Enter an integer: ");
   scanf("%ld", &number);
   
   result = fibonacci(number);
   
   printf("Fibonacci(%ld) = %llu\n\n", number, result);
}


long fibonacci(long n) {
  if (n == 0 || n == 1)
     return n;
  else
     return fibonacci(n - 1) + fibonacci(n - 2);
}
