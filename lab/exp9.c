#include <stdio.h>

int main()
{
    printf("Original Grammar:\n\n");

    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n");

    printf("\nGrammar after Eliminating Left Recursion:\n\n");

    printf("S -> (L) | a\n");
    printf("L -> SR\n");
    printf("R -> ,SR | e\n");

    return 0;
}
