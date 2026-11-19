#include <stdio.h>

int main(void)
{
int a, b, c, largest;

printf("Enter any three numbers: ");
if (scanf("%d %d %d", &a, &b, &c) != 3) {
printf("Invalid input.\n");
return 1;
}

if (a >= b && a >= c)
largest = a;
else if (b >= a && b >= c)
largest = b;
else
largest = c;

printf("Largest number = %d\n", largest);

return 0;
}
