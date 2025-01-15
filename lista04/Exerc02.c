/* 2- Ler um valor real qualquer e escrever se o mesmo é (estritamente) “Positivo”, */
/* “Negativo” ou igual a “Zero”. */

#include <stdio.h>

int main() {
    float num;

    printf("Digite um valor: ");
    scanf("%f", &num);

    if (num > 0) {
        printf("Positivo");
    } else if (num < 0) {
        printf("Negativo");
    } else {
        printf("Zero");
    }

    return 0;
}
