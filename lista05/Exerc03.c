/* 3 - Uma loja está levantando o valor total de todas as mercadorias em estoque. */
/* Escreva um algoritmo que permita a entrada das seguintes informações: a)  */
/* o número total de mercadorias no estoque; b) o valor de cada mercadoria.  */
/* Ao final, imprimir o valor total em estoque e a média de valor das mercadorias. */

#include <stdio.h>

int main() {
    int numMercadorias;
    float valor, total = 0.0, media;

    printf("Digite o numero total de mercadorias no estoque: ");
    scanf("%d", &numMercadorias);

    if (numMercadorias <= 0) {
        printf("O numero de mercadorias deve ser maior que zero.\n");
        return 1;
    }

    for (int i = 1; i <= numMercadorias; i++) {
        printf("Digite o valor da mercadoria %d: ", i);
        scanf("%f", &valor);
        total += valor;
    }

    media = total / numMercadorias;

    printf("Valor total em estoque: %.2f\n", total);
    printf("Media de valor das mercadorias: %.2f\n", media);

    return 0;
}
