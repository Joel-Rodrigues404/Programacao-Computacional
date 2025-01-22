/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 07 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie um programa em C que leia uma string de até 100 caracteres e verifique / informe se a */
/* mesma é um palíndromo ou não (ou seja, se a sequência de caracteres é a mesma quando */
/* lida de trás para frente). */
/* exemplos: ovo, arara, rever, asa, osso, ana etc. */

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char str2[100];

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);

    int tamanho_str = strlen(str);

    if (tamanho_str > 0 && str[tamanho_str - 1] == '\n') {
        str[tamanho_str - 1] = '\0';
        tamanho_str--;
    }

    int aux = 0;
    for (int i = tamanho_str - 1; i >= 0; i--) {
        str2[aux] = str[i];
        aux = aux + 1;
    }
    str2[aux] = '\0';

    if (strcmp(str, str2) == 0) {
        printf("E um palíndromo\n");
        printf("str1 = %s\nstr2 = %s", str, str2);
    }
    return 0;
}
