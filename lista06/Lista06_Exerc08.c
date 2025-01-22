/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 08 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie uma estrutura, representando um aluno de uma disciplina, onde essa estrutura deve */
/* conter o número de matrícula do aluno (um número inteiro), seu nome (com até 40 */
/* caracteres) e as notas de três provas (reais), além de um campo para a média de tais notas. */
/* Escreva um programa que leia os dados para povoar esta estrutura (matrícula, nome e 3 */
/* notas) e calcule e armazene a média das notas. Mostre o tamanho em bytes dessa estrutura. */

#include <stdio.h>

int main() {
    struct Aluno {
        int matricula;
        char nome[40];
        float nota1;
        float nota2;
        float nota3;
        float media;
    };

    struct Aluno aluno1;

    printf("Digite a matricula: ");
    scanf("%d", &aluno1.matricula);

    printf("Digite o nome: ");
    scanf("%s", aluno1.nome);

    printf("Digite a nota1: ");
    scanf("%f", &aluno1.nota1);

    printf("Digite a nota2: ");
    scanf("%f", &aluno1.nota2);

    printf("Digite a nota3: ");
    scanf("%f", &aluno1.nota3);

    aluno1.media = (aluno1.nota1 + aluno1.nota2 + aluno1.nota3) / 3;

    printf("O aluno %s obteve a media %.2f", aluno1.nome, aluno1.media);
    printf("Tamanho da estrutura Aluno: %zu bytes\n", sizeof(aluno1));
    return 0;
}
