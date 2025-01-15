/* 6 - Escreva um programa que verifique a validade de uma senha fornecida pelo usuário. */
/* A senha válida é “abacate”. Devem ser impressas as seguintes mensagens: */
/* “ACESSO PERMITIDO”, caso a senha seja válida. */
/* “ACESSO NEGADO”, caso a senha seja inválida. */

#include <stdio.h>
#include <string.h>

int main() {
    char *senha_correta = "abacate";
    char *senha;

    printf("Qual a senha: ");
    scanf("%s", &*senha);

    if (strcmp(senha, senha_correta) == 0) {
        printf("ACESSO PERMITIDO");
    } else {
        printf("ACESSO NEGADO");
    }

    return 0;
}
