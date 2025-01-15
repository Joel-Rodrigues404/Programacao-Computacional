/* 4 - Escreva um programa que receba/leia um número inteiro do usuário e informe se esse */
/* número é “Par” ou “Ímpar” */

#include <stdio.h>

int main() {
    int num;

    printf("Digite um valor: ");
    scanf("%d", &num);

    int paridade = num % 2;

    if (!paridade) {
        printf("Par");
    } else {
        printf("Impar");
    }

    return 0;
}
