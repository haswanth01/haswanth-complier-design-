#include <stdio.h>

int main()
{
    printf("Original Grammar:\n\n");

    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n");

    printf("\nGrammar after Left Factoring:\n\n");

    printf("S -> iEtSA | a\n");
    printf("A -> eS | e\n");
    printf("E -> b\n");

    return 0;
}
