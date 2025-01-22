/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 05 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie um programa em C que leia um valor inteiro positivo ‘n’ (representando o tamanho de */
/* uma matriz quadrada), então crie uma matriz de inteiros de tamanho n x n, leia os valores */
/* dos elementos desta matriz e, ao final, calcule e imprima o valor do determinante desta */
/* matriz. */

#include <stdio.h>

int calcularDeterminante(int matriz[10][10], int n) {
    int det = 0;
    if (n == 1) {
        return matriz[0][0];
    }
    if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    int submatriz[10][10];
    for (int x = 0; x < n; x++) {
        int sub_i = 0, sub_j = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                submatriz[sub_i][sub_j] = matriz[i][j];
                sub_j++;
                if (sub_j == n - 1) {
                    sub_j = 0;
                    sub_i++;
                }
            }
        }
        det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * calcularDeterminante(submatriz, n - 1);
    }
    return det;
}

int main() {
    int n;
    printf("Digite o tamanho da matriz (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("O tamanho da matriz deve ser um inteiro positivo e menor ou igual a 10.\n");
        return 1;
    }

    int matriz[10][10];
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int determinante = calcularDeterminante(matriz, n);
    printf("O determinante da matriz é: %d\n", determinante);

    return 0;
}
