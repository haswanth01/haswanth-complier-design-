#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[])
{
    char keywords[][20] = {
        "int", "float", "char", "double", "void",
        "if", "else", "for", "while", "do",
        "return", "break", "continue"
    };

    int i;

    for(i = 0; i < 13; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char id[100];
    int i;

    printf("Enter an identifier: ");
    scanf("%s", id);

    if(isKeyword(id))
    {
        printf("%s is NOT a valid identifier (Keyword).\n", id);
        return 0;
    }

    if(!(isalpha(id[0]) || id[0] == '_'))
    {
        printf("%s is NOT a valid identifier.\n", id);
        return 0;
    }

    for(i = 1; id[i] != '\0'; i++)
    {
        if(!(isalnum(id[i]) || id[i] == '_'))
        {
            printf("%s is NOT a valid identifier.\n", id);
            return 0;
        }
    }

    printf("%s is a VALID identifier.\n", id);

    return 0;
}
