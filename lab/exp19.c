#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char filename[100];
    char ch, next;

    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;

    printf("Enter C source file name: ");
    scanf("%99s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Single-line comment */
        if (ch == '/')
        {
            next = fgetc(fp);

            if (next == '/')
            {
                while ((ch = fgetc(fp)) != EOF && ch != '\n')
                    ;

                if (ch == '\n')
                    lines++;

                inWord = 0;
                continue;
            }

            /* Multi-line comment */
            else if (next == '*')
            {
                char prev = 0;

                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == '\n')
                        lines++;

                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }

                inWord = 0;
                continue;
            }

            else
            {
                ungetc(next, fp);
            }
        }

        /* Count newline */
        if (ch == '\n')
        {
            lines++;
            inWord = 0;
            continue;
        }

        /* Ignore spaces and tabs */
        if (ch == ' ' || ch == '\t' || ch == '\r')
        {
            inWord = 0;
            continue;
        }

        /* Count characters */
        characters++;

        /* Count words */
        if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    fclose(fp);

    printf("\nLEXICAL ANALYZER RESULT\n");
    printf("-----------------------\n");
    printf("Number of characters = %d\n", characters);
    printf("Number of words      = %d\n", words);
    printf("Number of lines      = %d\n", lines);

    return 0;
}
