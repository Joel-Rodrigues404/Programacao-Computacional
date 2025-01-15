/* 10 - Faça um programa para calcular o fatorial de um número digitado pelo */
/* usuário, usando o formato de cálculo iterativo (não recursivo). */

#include <stdio.h>

int main() {
    int num, i;
    int fatorial = 1;

    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fatorial não é definido para números negativos.\n");
    } else {
        for (i = 1; i <= num; i++) {
            fatorial *= i;
        }
        printf("O fatorial de %d é %d.\n", num, fatorial);
    }

    return 0;
}
