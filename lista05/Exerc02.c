/* 2 - Ler 2 valores do usuário, calcular e escrever a soma e a média dos inteiros existentes */
/* entre os 2 valores lidos (incluindo os valores lidos na soma). Observe que primeiro você */
/* precisa descobrir qual o maior e o menor valor digitado. */

#include <stdio.h>

int main() {
    int num1;
    int num2;

    int soma = 0;
    int cont = 0;
    float media;

    printf("Digite os numeros: ");
    scanf("%d %d", &num1, &num2);

    if (num1 >= num2) {
        printf("O primeiro numero deve ser menor que o segundo.\n");
        return 1;
    }

    for (int i = num1 + 1; i < num2; i++) {
        soma += i;
        printf("%d\n", i);
        cont++;
    }

    if (cont > 0) {
        media = (float)soma / cont;
        printf("Media e igual a: %.2f\n", media);
    } else {
        printf("Nao ha numeros entre %d e %d para calcular a media.\n", num1, num2);
    }

    return 0;
}
