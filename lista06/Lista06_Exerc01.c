/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 01 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Escreva um programa em C que declare e inicialize um array de inteiros com 5 elementos */
/* (contendo os valores de 1 a 5) e exiba os valores na tela, sendo um por linha, e em forma de */
/* “escada” ou diagonal. */
/* Modelo: */
/*
 1
  2
   3
    4
     5
*/

#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" ");
        }
        printf("%d\n", arr[i]);
    }
    return 0;
}
