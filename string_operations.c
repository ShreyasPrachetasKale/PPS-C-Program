/*
 * Lab Assignment 05 - Programming and Problem Solving
 * Menu driven program to perform string operations using the
 * built-in functions of <string.h> (and <ctype.h>).
 *
 * Compile : gcc string_operations.c -o string_operations
 * Run     : ./string_operations
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

/* Read a line safely and strip the trailing newline. */
static void readLine(const char *prompt, char *buf, int size)
{
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

static void lengthOp(void)
{
    char s[SIZE];
    readLine("Enter a string: ", s, SIZE);
    printf("Length of \"%s\" = %zu\n", s, strlen(s));
}

static void copyOp(void)
{
    char src[SIZE], dest[SIZE];
    readLine("Enter source string: ", src, SIZE);
    strcpy(dest, src);
    printf("Copied string = \"%s\"\n", dest);
}

static void concatOp(void)
{
    char s1[SIZE], s2[SIZE], result[2 * SIZE];
    readLine("Enter first string : ", s1, SIZE);
    readLine("Enter second string: ", s2, SIZE);
    strcpy(result, s1);
    strcat(result, s2);
    printf("Concatenated string = \"%s\"\n", result);
}

static void compareOp(void)
{
    char s1[SIZE], s2[SIZE];
    readLine("Enter first string : ", s1, SIZE);
    readLine("Enter second string: ", s2, SIZE);
    int r = strcmp(s1, s2);
    if (r == 0)
        printf("Both strings are equal.\n");
    else if (r < 0)
        printf("\"%s\" comes before \"%s\" (strcmp = %d).\n", s1, s2, r);
    else
        printf("\"%s\" comes after \"%s\" (strcmp = %d).\n", s1, s2, r);
}

static void reverseOp(void)
{
    char s[SIZE];
    readLine("Enter a string: ", s, SIZE);
    /* strrev() is not part of standard C, so reverse in place using strlen. */
    for (size_t i = 0, j = strlen(s); i + 1 < j; i++, j--) {
        char t = s[i];
        s[i] = s[j - 1];
        s[j - 1] = t;
    }
    printf("Reversed string = \"%s\"\n", s);
}

static void caseOp(int toUpper)
{
    char s[SIZE];
    readLine("Enter a string: ", s, SIZE);
    for (size_t i = 0; s[i] != '\0'; i++)
        s[i] = toUpper ? (char)toupper((unsigned char)s[i])
                       : (char)tolower((unsigned char)s[i]);
    printf("%s string = \"%s\"\n", toUpper ? "Uppercase" : "Lowercase", s);
}

static void findCharOp(void)
{
    char s[SIZE], c[SIZE];
    readLine("Enter a string   : ", s, SIZE);
    readLine("Enter a character: ", c, SIZE);
    if (c[0] == '\0') {
        printf("No character entered.\n");
        return;
    }
    char *p = strchr(s, c[0]);
    if (p)
        printf("'%c' first found at position %ld (0-based).\n", c[0], (long)(p - s));
    else
        printf("'%c' not found.\n", c[0]);
}

static void findSubstringOp(void)
{
    char s[SIZE], sub[SIZE];
    readLine("Enter main string: ", s, SIZE);
    readLine("Enter substring  : ", sub, SIZE);
    char *p = strstr(s, sub);
    if (p)
        printf("Substring found at position %ld (0-based): \"%s\"\n", (long)(p - s), p);
    else
        printf("Substring not found.\n");
}

int main(void)
{
    char line[16];
    int choice;

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf(" 1. Length of a string      (strlen)\n");
        printf(" 2. Copy a string           (strcpy)\n");
        printf(" 3. Concatenate two strings (strcat)\n");
        printf(" 4. Compare two strings     (strcmp)\n");
        printf(" 5. Reverse a string\n");
        printf(" 6. Convert to uppercase    (toupper)\n");
        printf(" 7. Convert to lowercase    (tolower)\n");
        printf(" 8. Find a character        (strchr)\n");
        printf(" 9. Find a substring        (strstr)\n");
        printf(" 0. Exit\n");
        printf("Enter your choice: ");

        if (fgets(line, sizeof line, stdin) == NULL)
            break;
        if (sscanf(line, "%d", &choice) != 1)
            choice = -1;

        switch (choice) {
        case 1: lengthOp();        break;
        case 2: copyOp();          break;
        case 3: concatOp();        break;
        case 4: compareOp();       break;
        case 5: reverseOp();       break;
        case 6: caseOp(1);         break;
        case 7: caseOp(0);         break;
        case 8: findCharOp();      break;
        case 9: findSubstringOp(); break;
        case 0: printf("Exiting program.\n"); break;
        default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
