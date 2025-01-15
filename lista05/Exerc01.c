/* 1 - Faça um programa que receba um número N do usuário */
/* e imprima os N primeiros termos da seguinte série: 1, 5, 9, 13, 17, 21, ... */

#include <stdio.h>

int main() {
    int n;
    int j = 1;

    printf("Digite o numero de elementos da serie: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", j);
        j = j + 4;
    }

    return 0;
}
