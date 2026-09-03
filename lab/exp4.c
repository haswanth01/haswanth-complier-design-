#include <stdio.h>

int main()
{
    char ch;

    printf("Enter an operator: ");
    scanf("%c", &ch);

    switch(ch)
    {
        case '+':
            printf("+ is an Arithmetic Operator (Addition)\n");
            break;

        case '-':
            printf("- is an Arithmetic Operator (Subtraction)\n");
            break;

        case '*':
            printf("* is an Arithmetic Operator (Multiplication)\n");
            break;

        case '/':
            printf("/ is an Arithmetic Operator (Division)\n");
            break;

        default:
            printf("%c is NOT an Arithmetic Operator.\n", ch);
    }

    return 0;
}
