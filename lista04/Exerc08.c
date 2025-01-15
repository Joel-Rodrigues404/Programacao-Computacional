/* 8 - Faça um programa para ler um salário e atualizá-lo (imprimindo na tela o novo valor) */
/* de acordo com a tabela abaixo. */

#include <stdio.h>

int main() {
    float salario;

    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    if (salario <= 600) {
        salario += salario * 0.30; // Aumento de 30%
    } else if (salario <= 1200) {
        salario += salario * 0.20; // Aumento de 20%
    } else if (salario <= 2000) {
        salario += salario * 0.10; // Aumento de 10%
    } else {
        salario += salario * 0.05; // Aumento de 5%
    }

    printf("O novo salário é: %.2f\n", salario);
    return 0;
}
