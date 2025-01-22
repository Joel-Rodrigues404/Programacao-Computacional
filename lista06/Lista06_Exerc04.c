/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 04 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Baseado na definição / enunciado da questão 3, após ler os 2 valores inteiros (l e c), crie / */
/* declare 2 matrizes de reais (double), sendo uma de dimensões de “l x c” e a outra de */
/* dimensões “c x l”. Depois, leia valores para os elementos de cada uma destas matrizes, e, ao */
/* final, calcule e informe o valor da multiplicação entre estas 2 matrizes. */

#include <stdio.h>

int main() {
    int l, c;
    double num;

    printf("Didite a quantidade de linhas e colunas da matriz: ");
    scanf("%d %d", &l, &c);

    double matriz1[l][c];
    double matriz2[c][l];
    double matrizResultado[l][l];

    // ler valores matriz1
    printf("Ler valores matriz1\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Digite o valor para a linha[%d] e coluna[%d]: ", i, j);
            scanf("%lf", &num);
            matriz1[i][j] = num;
        }
    }

    // ler valores matriz2
    printf("Ler valores matriz2\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            printf("Digite o valor para a linha[%d] e coluna[%d]: ", i, j);
            scanf("%lf", &num);
            matriz2[i][j] = num;
        }
    }

    // imprimir valores matriz1
    printf("Imprimir valores matriz1\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%lf\t", matriz1[i][j]);
        }
        printf("\n");
    }

    // imprimir valores matriz2
    printf("Imprimir valores matriz2\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            printf("%lf\t", matriz2[i][j]);
        }
        printf("\n");
    }

    // Inicializar a matriz resultado com zeros
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            matrizResultado[i][j] = 0.0;
        }
    }

    // faz a multiplicação
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < c; k++) {
                matrizResultado[i][j] += matriz1[j][k] * matriz2[k][j];
            }
        }
    }

    // Imprimir a matriz resultado
    printf("Matriz resultado da multiplicação:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            printf("%lf\t", matrizResultado[i][j]);
        }
        printf("\n");
    }
    return 0;
}
