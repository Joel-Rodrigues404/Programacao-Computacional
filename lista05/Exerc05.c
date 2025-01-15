/* 5 - Faça um programa que leia um valor e diga se o número digitado é primo ou não. */

#include <stdio.h>

int main() {
    int numero, i, primo = 1;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero <= 1) {
        primo = 0;
    } else {
        for (i = 2; i <= numero / 2; i++) {
            if (numero % i == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo) {
        printf("%d eh primo.\n", numero);
    } else {
        printf("%d nao eh primo.\n", numero);
    }

    return 0;
}
