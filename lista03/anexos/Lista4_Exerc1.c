/*
    seu nome: Joel Anderson Rodrigues
    número de matrícula: 571518
    data atual: 28/11/2024
    ambiente / ferramenta: AstroNvim
*/

#include <stdio.h>
#include <string.h>

// 2) Escreva um único programa em C que atenda aos itens de a) até e) listados
// abaixo e salve tal código com o nome de “Lista4_Exerc1.c”. Insira comentários
// no cabeçalho (início) de tal código, informando seu nome, número de
// matrícula, data atual e ambiente / ferramenta utilizada para escrita /
// execução do código:

int main() {
    // A) Declare 2 variáveis inteiras, 2 variáveis reais e 2 variáveis do tipo
    // caracter;
    int num_int1;
    int num_int2;

    float num_float1;
    float num_float2;

    char string1[10];
    char string2[10];

    // b) Atribua valores distintos (porém válidos) a cada uma destas variáveis;
    num_int1 = 1;
    num_int2 = 2;

    num_float1 = 3.5;
    num_float2 = 4.5;

    strcpy(string1, "1string1");
    strcpy(string2, "2string2");

    // C) Faça a troca dos valores das 2 variáveis inteiras sem utilizar uma 3ª
    // variável para isso;
    num_int1 = num_int1 - num_int2;
    num_int2 = num_int2 + num_int1;
    num_int1 = num_int2 - num_int1;

    // d) Tente atribuir variáveis de tipos distintos (umas às outras) e observe
    // informe o que acontece quanto tenta compilar o código do programa;
    // Resposta -> Na hora da compilação ocorrem diversos erros por causa dos
    // tipos das variaveis
    //             o codigo não e compilado a IDE tambem descreve o erro o
    //             codigo do erro e a linha onde possivelmente foi o erro abaixo
    //             uma breve descrição dos erros que chamam atenção

    // diz que o ponteiro não esta apontando para um tipo inteiro
    /* num_int1 = "s"; */
    // diz que ocorre uma conversão implicita de int para double
    /* num_int2 = 2.3; */
    // não ocorre erro
    /* num_float1 = 3; */
    // diz que o tipo char[2] e imcompativel com float
    /* num_float2 = "d"; */

    // diz que ocorre uma conversão imcompativel para inteiro
    /* strcpy(string1, 11); */
    // esse erro e interessante pois apesar de ser um char ele diz que ocorre
    // uma conversão imcompativel para inteiro acredito que seja porque o char
    // de com aspas simples seja convertido para o valor numerico da tabela
    // ASCII
    /* strcpy(string2, 's'); */

    // e) Descreva o que acontece quando se tenta fazer uma operação inválida
    // (como uma divisão por Zero (/0).
    // Resposta -> A principio pelo menos na minha IDE e para os valores
    // inteiros e de ponto flutuante não ocorre nenhum erro ou nenhuma exceção
    num_int1 = 0;
    num_int2 = 0;
    int div = num_int1 / num_int2;
    printf("%i\n", div);

    num_float1 = 0.0;
    num_float2 = 0.0;
    float div2 = num_float1 / num_float2;
    printf("%f\n", div2);

    return 0;
}
