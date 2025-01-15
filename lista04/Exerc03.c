/* 3 - Ler as notas da 1a. e 2a. avaliações de um aluno. Calcular a média aritmética simples */
/* e escrever uma mensagem que diga se o aluno foi ou não aprovado (considerar que nota */
/* igual ou maior que 6 o aluno é aprovado). Escrever também a média calculada. */

#include <stdio.h>

int main() {
    float nota1;
    float nota2;

    printf("Digite o valor da nota 1 ");
    scanf("%f", &nota1);

    printf("Digite o valor da nota 2 ");
    scanf("%f", &nota2);

    float media = (nota1 + nota2) / 2;

    if (media >= 6) {
        printf("Aprovado com media %.2f", media);
    } else {
        printf("Reprovado com media %.2f", media);
    }

    return 0;
}
