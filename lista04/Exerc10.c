/* 10 – Escreva um programa que calcule a média de cada aluno de uma disciplina, */
/* seguindo a seguinte fórmula: */
/* ou media = (P1 ∗ N1 + P2 ∗ N2) / (P1 + P2) */
/* Em que o programa deve ler os seguintes valores reais N1 e N2 (que são as notas de */
/* cada aluno da disciplina) e P1 e P2 (que são os respectivos pesos destas notas). */
/* Informe a média e se o aluno foi “Aprovado” (média maior ou igual a 7,0), ficou de */
/* “Final” (média menor que 7,0 e maior ou igual a 4,0) ou se ficou “Reprovado” */
/* (média menor do que 4,0). */

#include <stdio.h>

int main() {
    float N1, P1, N2, P2, media;

    printf("Digite a nota N1: ");
    scanf("%f", &N1);
    printf("Digite o peso P1: ");
    scanf("%f", &P1);
    printf("Digite a nota N2: ");
    scanf("%f", &N2);
    printf("Digite o peso P2: ");
    scanf("%f", &P2);

    media = (P1 * N1 + P2 * N2) / (P1 + P2);

    printf("Média: %.2f\n", media);

    if (media >= 7.0) {
        printf("Situação: Aprovado\n");
    } else if (media >= 4.0) {
        printf("Situação: Final\n");
    } else {
        printf("Situação: Reprovado\n");
    }

    return 0;
}
