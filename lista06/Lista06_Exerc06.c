/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 06 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie um programa em C que leia uma matriz de inteiros de tamanho 5x5 e verifique / */
/* informe se todos os elementos são números primos (ou não). */

#include <stdio.h>

int main() {
    int n = 5;
    int num_primos = 0;
    int num;
    int matriz1[n][n];

    // ler valores matriz1
    printf("Ler valores matriz1\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o valor para a linha[%d] e coluna[%d]: ", i, j);
            scanf("%d", &num);
            matriz1[i][j] = num;
        }
    }

    // imprimir valores matriz1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int div = 0;
            if (matriz1[i][j] == 0 || matriz1[i][j] == 1) {
                printf("Nem todos os elementos são primos!");
                break;
            }
            for (int k = 1; k <= matriz1[i][j]; k++) {
                if (matriz1[i][j] % k == 0) {
                    div = div + 1;
                }
            }
            if (div == 2) {
                num_primos += 1;
            }
        }
    }

    if (num_primos == (n * n)) {
        printf("Todos os numeros da matriz são primos!");
    } else if (num_primos != (n * n)) {
        printf("Nem todos os numeros são primos!");
    }
    return 0;
}
