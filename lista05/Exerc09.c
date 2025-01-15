/* 9 - Faça um programa que leia um valor do usuário e informe se */
/* o número digitado é primo ou não, usando laço de repetição em tal cálculo. */

#include <stdio.h>

int main() {
    int num, i, primo = 1;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

    if (num <= 1) {
        primo = 0;
    } else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo) {
        printf("%d é um número primo.\n", num);
    } else {
        printf("%d não é um número primo.\n", num);
    }

    return 0;
}
