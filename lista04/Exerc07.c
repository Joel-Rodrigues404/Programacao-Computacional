/* 7 - Faça um programa para ler dois números inteiros A e B e informar se “A é divisível */
/* por B”. */

#include <stdio.h>

int main() {
    int a;
    int b;

    printf("digite dois numeros: ");
    scanf("%d %d", &a, &b);

    (a % b == 0) ? printf("A é divisível por b") : printf("A não e divisível por b");
    return 0;
}
