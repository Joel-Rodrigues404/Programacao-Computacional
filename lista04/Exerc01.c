/* 1 - Ler um valor e escrever a mensagem “É MAIOR QUE 10!” se o valor lido for
 * maior */
/* que 10, caso contrário escrever “NÃO É MAIOR QUE 10!” */

#include <stdio.h>

int main() {
    int num;

    printf("Digite um valor: ");
    scanf("%d", &num);

    if (num > 10) {
        printf("É MAIOR QUE 10!");
    } else {
        printf("NÃO É MAIOR QUE 10!");
    }
    return 0;
}
