/* 7 - A sequência de números 0 1 1 2 3 5 8 13 21... é conhecida como Série de Fibonacci. */
/* Nessa sequência, cada número, depois dos 2 primeiros (fixados em 0 e 1), é igual à soma */
/* 1 dos 2 anteriores. Escreva um programa em C que receba como parâmetro um inteiro positivo */
/* N (0 < N < 46) e mostre os N primeiros números dessa série, separados por espaço. */

#include <stdio.h>

int main() {
    int N, i;
    long long fib[N];

    printf("Digite um número inteiro positivo (0 < N < 46): ");
    scanf("%d", &N);

    if (N <= 0 || N >= 46) {
        printf("Valor de N deve estar entre 1 e 45.\n");
        return 1;
    }

    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (i = 0; i < N; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    return 0;
}
