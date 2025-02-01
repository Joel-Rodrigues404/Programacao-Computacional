/* teste.c */
#include <stdio.h>
#include <string.h>

int main() {
    typedef struct {
        char nome[41];
        int idade;
        int cpf[12];
        char estado_civil;
    } Pessoa;

    Pessoa pessoa;

    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\n';

    return 0;
}
