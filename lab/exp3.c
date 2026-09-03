#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[])
{
    char keywords[][20] = {
        "int", "float", "char", "double", "void",
        "if", "else", "for", "while", "do",
        "return", "break", "continue"
    };

    int i;

    for(i = 0; i < 13; i++)
    {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char str[1000];
    int i = 0;

    printf("Enter C program/code:\n");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0')
    {
        /* Ignore spaces, tabs and newlines */
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++;
            continue;
        }

        /* Ignore single-line comments */
        if(str[i] == '/' && str[i + 1] == '/')
        {
            break;
        }

        /* Ignore multi-line comments */
        if(str[i] == '/' && str[i + 1] == '*')
        {
            i += 2;

            while(str[i] != '\0')
            {
                if(str[i] == '*' && str[i + 1] == '/')
                {
                    i += 2;
                    break;
                }
                i++;
            }
            continue;
        }

        /* Keywords and Identifiers */
        if(isalpha(str[i]) || str[i] == '_')
        {
            char token[50];
            int j = 0;

            while(isalnum(str[i]) || str[i] == '_')
            {
                token[j++] = str[i];
                i++;
            }

            token[j] = '\0';

            if(isKeyword(token))
                printf("%s --> Keyword\n", token);
            else
                printf("%s --> Identifier\n", token);

            continue;
        }

        /* Constants */
        if(isdigit(str[i]))
        {
            char token[50];
            int j = 0;

            while(isdigit(str[i]))
            {
                token[j++] = str[i];
                i++;
            }

            token[j] = '\0';

            printf("%s --> Constant\n", token);
            continue;
        }

        /* Operators */
        if(strchr("+-*/=%<>!", str[i]) != NULL)
        {
            printf("%c --> Operator\n", str[i]);
            i++;
            continue;
        }

        /* Special Symbols */
        printf("%c --> Special Symbol\n", str[i]);
        i++;
    }

    return 0;
}
