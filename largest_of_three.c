/*
 * Lab Assignment 02 - Programming and Problem Solving
 * Program to find the largest among three numbers.
 *
 * Compile : gcc largest_of_three.c -o largest_of_three
 * Run     : ./largest_of_three
 */
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
