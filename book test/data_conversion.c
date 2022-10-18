#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int A = 10;
    char B = 'X';
    float C = 2.30;

    printf("\nValor inicial de A: %d\n", A);
    printf("\nValor inicial de B: %c\n", B);
    printf("\nValor inicial de C: %.2f\n", C);

    A = C; //a variavel A (int) recebera a parte inteira de C (float)
    printf("\nA = C, valor de A: %d\n", A);
    C = A; //a variavel A (int) sera convertida em um float (C)
    printf("\nC = A, valor de C: %f\n", C);
    B = A; //a variavel B (char) recebera os bits de A (int)
    printf("\nB = A, valor de B: %d\n", B);
    C = B; //a variavel C (float) recebera os bits de B (char)
    printf("\nC = B, valor de C: %.2f\n", C);
    return (0);
}