#include <stdio.h>
#include <string.h>

int main(void)
{
const char savedEmail[] = "user@gmail.com";
const char savedPass[] = "pass123";

char email[50], pass[50];

do {
printf("Enter email ID: ");
if (scanf("%49s", email) != 1)
return 1;

if (strcmp(email, savedEmail) != 0)
printf("Couldn't find your Google Account.\n");
} while (strcmp(email, savedEmail) != 0);

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
