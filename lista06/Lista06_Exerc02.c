/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 02 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie um programa em C que leia um array de valores inteiros (estritamente não negativos) */
/* com 10 elementos e então exiba o maior, o menor, a soma e a média de todos os valores. Ao */
/* final, imprimir os valores digitados na ordem inversa, separados por vírgula. OBS.: O */
/* programa deve “garantir” que não serão aceitos / lidos valores negativos. */

#include <stdio.h>

int main() {
    int arr[10];
    int num;
    int maior, menor, soma;
    float media;

    for (int i = 0; i <= 9; i++) {
        printf("Digite um numero: ");
        scanf("%d", &num);

        if (num < 0) {
            printf("O numero não pode ser negativo!");
            break;
        }

        if (i == 0) {
            maior = num;
            menor = num;
        }

        if (num > maior) {
            maior = num;
        }

        if (num < menor) {
            menor = num;
        }
        soma = soma + num;
        arr[i] = num;
    }

    for (int j = 9; j >= 0; j--) {
        if (j == 0) {
            printf("%d", arr[j]);
        } else {
            printf("%d,", arr[j]);
        }
    }
    printf("\nmaior = %d\nmenor = %d", maior, menor);
    printf("\nmedia = %.2f", soma / 10.0);

    return 0;
}
