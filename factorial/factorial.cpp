// C program to find factorial of given number 
// Función factorial modficada, basada en los codigos de https://www.geeksforgeeks.org/c-program-for-factorial-of-a-number/ y  https://www.programiz.com/c-programming/examples/factorial

#include "iostream"
#include "string"
#include <stdio.h> 
using namespace std;


// Factorial
unsigned int factorial(unsigned int n) 
{ 
	if (n == 0) 
		return 1; 
	return n * factorial(n - 1); 
} 

// Driver code 
int main() 
{ 
    int n;
    printf("Enter an integer: ");
    cin >> n;
    int num = n; 
    printf("Factorial of %d is %d", 
           num, factorial(num)); 
    return 0; 
} 

