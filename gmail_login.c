/*
 * Lab Assignment 01 - Programming and Problem Solving
 * Program simulating a Gmail account login.
 *
 * Compile : gcc gmail_login.c -o gmail_login
 * Run     : ./gmail_login
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    /* Stored (dummy) account details */
    const char savedEmail[] = "user@gmail.com";
    const char savedPass[]  = "pass123";

    char email[50], pass[50];

    /* Input email until the account is found */
    do {
        printf("Enter email ID: ");
        if (scanf("%49s", email) != 1)
            return 1;

        if (strcmp(email, savedEmail) != 0)
            printf("Couldn't find your Google Account.\n");
    } while (strcmp(email, savedEmail) != 0);

    /* Input password until it is correct */
    do {
        printf("Enter password: ");
        if (scanf("%49s", pass) != 1)
            return 1;

        if (strcmp(pass, savedPass) != 0)
            printf("Wrong password. Try again.\n");
    } while (strcmp(pass, savedPass) != 0);

    printf("Login successful. Displaying Gmail Inbox...\n");

    return 0;
}
