#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int len;

    printf("Enter a line:\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    /* Check for single-line comment */
    if(str[0] == '/' && str[1] == '/')
    {
        printf("It is a Single Line Comment.\n");
    }

    /* Check for multi-line comment */
    else if(str[0] == '/' && str[1] == '*' &&
            len >= 4 &&
            str[len-3] == '*' &&
            str[len-2] == '/')
    {
        printf("It is a Multi Line Comment.\n");
    }

    else
    {
        printf("It is NOT a Comment.\n");
    }

    return 0;
}
