/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 09 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie um novo tipo de dados (chamado cadastro) a partir de uma estrutura que deve conter o */
/* “nome completo” (com até 50 caracteres), o “telefone” (com 11 dígitos incluindo o DDD) e */
/* o “endereço” (com rua, número, complemento, bairro, cidade, estado e CEP) de uma pessoa. */
/* Peça ao usuário para entrar com um inteiro positivo N (maior do que 0 e menor do que 6) e */
/* crie um vetor de tamanho N, de elementos de cadastro. Solicite também que o usuário entre */
/* com os dados para o povoamento desse vetor (ou seja, entrar com os dados de cadastro de N */
/* pessoas) e, ao final, imprima os dados digitados. */

#include <stdio.h>

#define MAX_PESSOAS 5

typedef struct {
    char nome[51];
    char telefone[12];
    struct {
        char rua[51];
        int numero;
        char complemento[21];
        char bairro[41];
        char cidade[41];
        char estado[3];
        char cep[10];
    } endereco;
} cadastro;

int main() {
    int N;
    cadastro pessoas[MAX_PESSOAS];

    do {
        printf("Digite um inteiro positivo N (1 a 5): ");
        scanf("%d", &N);
    } while (N <= 0 || N > MAX_PESSOAS);

    for (int i = 0; i < N; i++) {
        printf("\nCadastro da pessoa %d:\n", i + 1);

        printf("Nome completo: ");
        scanf(" %[^\n]", pessoas[i].nome);

        printf("Telefone (11 dígitos incluindo DDD): ");
        scanf("%s", pessoas[i].telefone);

        printf("Rua: ");
        scanf(" %[^\n]", pessoas[i].endereco.rua);

        printf("Número: ");
        scanf("%d", &pessoas[i].endereco.numero);

        printf("Complemento: ");
        scanf(" %[^\n]", pessoas[i].endereco.complemento);

        printf("Bairro: ");
        scanf(" %[^\n]", pessoas[i].endereco.bairro);

        printf("Cidade: ");
        scanf(" %[^\n]", pessoas[i].endereco.cidade);

        printf("Estado (sigla de 2 caracteres): ");
        scanf("%s", pessoas[i].endereco.estado);

        printf("CEP (8 dígitos): ");
        scanf("%s", pessoas[i].endereco.cep);
    }

    printf("\nDados cadastrados:\n");
    for (int i = 0; i < N; i++) {
        printf("\nCadastro da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Telefone: %s\n", pessoas[i].telefone);
        printf("Endereço: %s, %d, %s, %s, %s, %s, %s\n",
               pessoas[i].endereco.rua,
               pessoas[i].endereco.numero,
               pessoas[i].endereco.complemento,
               pessoas[i].endereco.bairro,
               pessoas[i].endereco.cidade,
               pessoas[i].endereco.estado,
               pessoas[i].endereco.cep);
    }

    return 0;
}
