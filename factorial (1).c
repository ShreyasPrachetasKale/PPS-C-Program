#include <stdio.h>

unsigned long long factIterative(int n)
{
unsigned long long result = 1;
for (int i = 2; i <= n; i++)
result *= i;
return result;
}

unsigned long long factRecursive(int n)
{
if (n == 0 || n == 1)
return 1;
return n * factRecursive(n - 1);
}

int main(void)
{
int n;

printf("Enter a number: ");
if (scanf("%d", &n) != 1) {
printf("Invalid input.\n");
return 1;
}

if (n < 0) {
printf("Factorial is not defined for negative numbers.\n");
return 1;
}
if (n > 20) {
printf("Number too large (max 20 for 64-bit unsigned result).\n");
return 1;
}

printf("Factorial of number (without recursion) = %llu\n", factIterative(n));
printf("Factorial of number (with recursion)    = %llu\n", factRecursive(n));

return 0;
}
