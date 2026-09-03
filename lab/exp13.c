#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

/* Grammar:
   S -> aSb | epsilon
*/

int S()
{
    /* If current symbol is 'a' */
    if (input[pos] == 'a')
    {
        pos++;          // Match 'a'

        if (!S())       // Parse S
            return 0;

        if (input[pos] == 'b')
        {
            pos++;      // Match 'b'
            return 1;
        }

        return 0;
    }

    /* epsilon production */
    return 1;
}

int main()
{
    printf("Enter the input string: ");
    scanf("%99s", input);

    pos = 0;

    if (S() && input[pos] == '\0')
    {
        printf("String is ACCEPTED.\n");
        printf("The input string satisfies the grammar.\n");
    }
    else
    {
        printf("String is REJECTED.\n");
        printf("The input string does not satisfy the grammar.\n");
    }

    return 0;
}
