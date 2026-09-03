#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[])
{
    char keywords[][20] = {
        "int", "float", "char", "if", "else", "while",
        "for", "return", "void", "double", "break", "continue"
    };

    int i;
    int n = 12;

    for(i = 0; i < n; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char str[1000];
    int i = 0;

    printf("Enter a line of C code:\n");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0')
    {
        /* Ignore spaces, tabs, and newlines */
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++;
            continue;
        }

        /* Ignore single-line comments */
        if(str[i] == '/' && str[i+1] == '/')
        {
            break;
        }

        /* Ignore multi-line comments */
        if(str[i] == '/' && str[i+1] == '*')
        {
            i += 2;

            while(str[i] != '\0')
            {
                if(str[i] == '*' && str[i+1] == '/')
                {
                    i += 2;
                    break;
                }
                i++;
            }
            continue;
        }

        /* Identifier or Keyword */
        if(isalpha((unsigned char)str[i]) || str[i] == '_')
        {
            char token[50];
            int j = 0;

            while(isalnum((unsigned char)str[i]) || str[i] == '_')
            {
                token[j++] = str[i++];
            }

            token[j] = '\0';

            if(isKeyword(token))
                printf("%s --> Keyword\n", token);
            else
                printf("%s --> Identifier\n", token);

            continue;
        }

        /* Constant */
        if(isdigit((unsigned char)str[i]))
        {
            char token[50];
            int j = 0;

            while(isdigit((unsigned char)str[i]))
            {
                token[j++] = str[i++];
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
