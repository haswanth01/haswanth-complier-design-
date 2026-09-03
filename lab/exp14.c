#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;
int temp = 1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void generateTAC(char expr[])
{
    char operands[100][20];
    char operators[100];
    int opTop = -1;
    int operandTop = -1;

    int i = 0;

    while (expr[i] != '\0')
    {
        /* Ignore spaces */
        if (expr[i] == ' ')
        {
            i++;
            continue;
        }

        /* Operand */
        if (isalnum(expr[i]))
        {
            char operand[20];
            int j = 0;

            while (isalnum(expr[i]))
            {
                operand[j++] = expr[i++];
            }

            operand[j] = '\0';

            strcpy(operands[++operandTop], operand);
        }

        /* Opening bracket */
        else if (expr[i] == '(')
        {
            operators[++opTop] = expr[i];
            i++;
        }

        /* Closing bracket */
        else if (expr[i] == ')')
        {
            while (opTop >= 0 && operators[opTop] != '(')
            {
                char op = operators[opTop--];

                char right[20], left[20], result[20];

                strcpy(right, operands[operandTop--]);
                strcpy(left, operands[operandTop--]);

                sprintf(result, "t%d", temp++);

                printf("%s = %s %c %s\n",
                       result, left, op, right);

                strcpy(operands[++operandTop], result);
            }

            opTop--;
            i++;
        }

        /* Operator */
        else
        {
            while (opTop >= 0 &&
                   operators[opTop] != '(' &&
                   precedence(operators[opTop]) >= precedence(expr[i]))
            {
                char op = operators[opTop--];

                char right[20], left[20], result[20];

                strcpy(right, operands[operandTop--]);
                strcpy(left, operands[operandTop--]);

                sprintf(result, "t%d", temp++);

                printf("%s = %s %c %s\n",
                       result, left, op, right);

                strcpy(operands[++operandTop], result);
            }

            operators[++opTop] = expr[i];
            i++;
        }
    }

    /* Process remaining operators */
    while (opTop >= 0)
    {
        char op = operators[opTop--];

        char right[20], left[20], result[20];

        strcpy(right, operands[operandTop--]);
        strcpy(left, operands[operandTop--]);

        sprintf(result, "t%d", temp++);

        printf("%s = %s %c %s\n",
               result, left, op, right);

        strcpy(operands[++operandTop], result);
    }
}

int main()
{
    char expression[100];

    printf("Enter an expression: ");
    scanf("%99s", expression);

    printf("\nThree Address Code:\n");
    generateTAC(expression);

    return 0;
}
