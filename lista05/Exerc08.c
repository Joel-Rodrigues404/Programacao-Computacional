/* 8 - Usando laços aninhados, implemente um programa que exiba as operações */
/* da tabuada de somar, subtrair e multiplicar. O programa deve solicitar ao */
/* usuário que escolha qual operação quer exibir. Se Soma, Subtração, Multiplicação ou Todas. */

#include <stdio.h>

int main() {
    int i, j, escolha;

    printf("Escolha a operação desejada:\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Todas\n");
    printf("Digite sua escolha (1-4): ");
    scanf("%d", &escolha);

    printf("\n");

    for (i = 1; i <= 10; i++) {
        switch (escolha) {
        case 1: // Soma
            printf("%d + %d = %d\n", i, 1, i + 1);
            break;
        case 2: // Subtração
            printf("%d - %d = %d\n", i, 1, i - 1);
            break;
        case 3: // Multiplicação
            printf("%d * %d = %d\n", i, 1, i * 1);
            break;
        case 4: // Todas
            printf("%d + %d = %d\n", i, 1, i + 1);
            printf("%d - %d = %d\n", i, 1, i - 1);
            printf("%d * %d = %d\n", i, 1, i * 1);
            break;
        default:
            printf("Escolha inválida.\n");
            return 1;
        }
    }

    return 0;
}
