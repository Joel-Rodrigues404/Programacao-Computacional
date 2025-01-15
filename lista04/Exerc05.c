/* 5 - Fazer um programa que lê um valor real, um operador aritmético (+,-,*,/) e outro */
/* valor real e imprime o resultado da expressão, de acordo com a seguinte entrada: */
/* <valor 1><operador><valor 2> */
/* e produza a seguinte saída: = <resultado> onde <resultado> informa o resultado da */
/* expressão aritmética dada como entrada. */

#include <stdio.h>

int main() {
    float num2;
    float num1;
    char operador;
    float resultado;

    printf("Digite a operação que deseja efetuar: ");
    scanf("%f %c %f", &num1, &operador, &num2);

    getchar();

    do {
        if (operador != '+' && operador != '-' && operador != '*' && operador != '/') {
            printf("Digite o operador: ");
            printf("Deve ser um desses valores: +, -, *, /\n");

            scanf("%c", &operador);
        } else {
            break;
        }
        getchar();
    } while (operador != '+' && operador != '-' && operador != '*' && operador != '/');

    switch (operador) {
    case '+':
        resultado = num1 + num2;
        break;
    case '-':
        resultado = num1 - num2;
        break;
    case '*':
        resultado = num1 * num2;
        break;
    case '/':
        resultado = num1 / num2;
        break;
    }

    printf("Resultado = %.2f", resultado);

    return 0;
}
