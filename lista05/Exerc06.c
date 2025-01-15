/* 6 - Faça um programa em C que, lendo a altura (h) */
/* de um triângulo, o programa desenhe tal triângulo na tela, usando um padrão com “*”s (asteriscos), */
/* conforme o seguinte exemplo: para: h = 5  */
/*     *  */
/*    *** */
/*   ***** */
/*  ******* */
/* ********* */

#include <stdio.h>

int main() {
    int h, i, j, k;

    printf("Digite a altura do triângulo: ");
    scanf("%d", &h);

    for (i = 1; i <= h; i++) {
        for (j = 1; j <= h - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
