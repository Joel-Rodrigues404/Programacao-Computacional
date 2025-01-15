/* 4 - O mesmo exercício anterior, mas agora não será informado o número de mercadorias em estoque */
/* . Então o funcionamento deverá ser da seguinte forma: ler o valor da mercadoria e */
/* perguntar ‘MAIS MERCADORIAS (S/N)?’. Ao final, imprimir o valor total em estoque e  */
/* a média de valor das mercadorias em estoque. */

#include <stdio.h>

int main() {
    float valor, total = 0.0, media;
    int cont = 0;
    char resposta;

    do {
        printf("Digite o valor da mercadoria: ");
        scanf("%f", &valor);
        total += valor;
        cont++;
        printf("MAIS MERCADORIAS (S/N)? ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');

    if (cont > 0) {
        media = total / cont;
        printf("Valor total em estoque: %.2f\n", total);
        printf("Media de valor das mercadorias: %.2f\n", media);
    } else {
        printf("Nenhuma mercadoria foi registrada.\n");
    }

    return 0;
}
