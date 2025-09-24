#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    if (n < 0) return -1; // factorial not defined for negative numbers

    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);

    // Validate input
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers\n");
        return 0;
    }

    long long result = factorial(n);
    printf("%d! = %lld\n", n, result);

    return 0;
}
