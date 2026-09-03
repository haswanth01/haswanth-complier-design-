#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int i;
    int spaces = 0;
    int newlines = 0;

    printf("Enter text:\n");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            spaces++;
        else if(str[i] == '\n')
            newlines++;
    }

    printf("Spaces = %d\n", spaces);
    printf("New Lines = %d\n", newlines);

    return 0;
}
