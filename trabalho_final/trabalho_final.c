/*
 * JOGO DE PALAVRAS INFERNAL
 * Compilador: ANSI C (C89)
 *
 * Participantes:
 * Nome: ANA VITÓRIA PINHEIRO GOMES
 * Matrícula: 571392;
 * Email: anavitoriapinheirogomes29@gmail.com;
 * Nome: DIANA MARIA MELO MATOS
 * Matrícula: 569948;
 * Email: dianamariamelo09@gmail.com;
 * Nome: JOEL ANDERSSON RODRIGUES
 * Matrícula: 571518;
 * Email: joelrodrigues@aluno.ufc.br;
 *
 * Processamento do código:
 * - Converte todo o texto para maiúsculas
 * - Converte todo o texto para minúsculas
 * - Inversão de caixa
 * - Apenas a primeira letra da frase em maiúscula
 * - Primeira Letra de Cada Palavra em Maiúscula, Exceto Conectivos
 * - Mostrar a frase original
 * - Nova palavra / Sair
 */

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAMANHO_MAXIMO 101                /* Tamanho máximo da string */
#define NOME_ARQUIVO "texto_original.txt" /* Nome do arquivo para salvar o texto */

/* Lista de conectivos que não devem ser capitalizados */
char *conectivos[] = {
    "de", "do", "dos", "da", "das", "a", "as", "o", "os", "ao", "aos",
    "no", "nos", "na", "nas", "em", "por", "e", "sobre", "com", "ate",
    "apos", "contra", "desde", "entre", "para", "sem", "sob", "nem",
    "que", "se", "mas", "ainda", "assim"};

int num_conectivos = sizeof(conectivos) / sizeof(conectivos[0]); /* Número de conectivos */

/* Função para salvar o texto original em um arquivo */
void salvarTextoOriginal(const char *texto) {
    FILE *file = fopen(NOME_ARQUIVO, "w");
    if (file != NULL) {
        printf("\nTexto Armanezado com Sucesso!\nTexto>> %s\n", texto);
        fprintf(file, "%s", texto);
        fclose(file);
    } else {
        printf("Erro ao salvar o arquivo.\n");
    }
}

/* Função para carregar o texto original do arquivo */
void carregarTextoOriginal(char *texto) {
    FILE *file = fopen(NOME_ARQUIVO, "r");
    if (file != NULL) {
        fgets(texto, TAMANHO_MAXIMO, file);
        fclose(file);
    } else {
        printf("Erro ao carregar o arquivo.\n");
    }
}

/* Função para limpar o buffer de entrada */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

/* Função para validar a string (somente letras e espaços são permitidos) */
int valida_string(char *texto) {
    int i, cont_letras = 0, cont_caracteres_indesejadas = 0;
    size_t tamanho = strlen(texto);

    for (i = 0; texto[i] != '\0'; i++) {

        if (!isalpha(texto[i]) && texto[i] != ' ' && texto[i] != '\n') {
            cont_caracteres_indesejadas++;
        }
        if (isalpha(texto[i])) {
            cont_letras++;
        }
    }

    if (i == 1 && texto[i] == '\0') {
        printf("ERRO: O texto não pode ser vazio!!!\n\n");
        return 0;
    } else if (cont_caracteres_indesejadas > 0) {
        printf("ERRO: Não deve conter símbolos ou números nem letras acentuadas!!\n\n");
        return 0;
    } else if (cont_letras == 0) {
        printf("ERRO: Deve conter pelo menos uma letra!!!\n\n");
        return 0;
    }

    return 1;
}

/* Função para converter todas as letras para maiúsculas */
void paraMaiusculas(char *texto) {
    int i;
    for (i = 0; texto[i]; i++) {
        texto[i] = toupper(texto[i]);
    }
}

/* Função para converter todas as letras para minúsculas */
void paraMinusculas(char *texto) {
    int i;
    for (i = 0; texto[i]; i++) {
        texto[i] = tolower(texto[i]);
    }
}

/* Função para inverter a caixa das letras (maiúsculas para minúsculas e vice-versa) */
void inverterCaixa(char *texto) {
    int i;
    for (i = 0; texto[i]; i++) {
        if (isupper(texto[i]))
            texto[i] = tolower(texto[i]);
        else if (islower(texto[i]))
            texto[i] = toupper(texto[i]);
    }
}

/* Função para capitalizar apenas a primeira letra da frase */
void primeiraLetraMaiuscula(char *texto) {
    int i = 0;
    while (texto[i] == ' ')
        i++;

    if (texto[i] != '\0') {
        texto[i] = toupper(texto[i]);
    }
}

/* Funação para capitalizar a primeira letra de cada palavra, exceto conectivos */
void capitalizarPalavras(char *texto) {
    int novoInicio = 1, ehConectivo = 0;
    char palavra[TAMANHO_MAXIMO], resultado[TAMANHO_MAXIMO];
    int i = 0, j = 0, k = 0;

    resultado[0] = '\0';
    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            palavra[j++] = tolower(texto[i]);
        } else {
            if (j > 0) {
                palavra[j] = '\0';
                ehConectivo = 0;
                for (k = 0; k < num_conectivos; k++) {
                    if (strcmp(palavra, conectivos[k]) == 0) {
                        ehConectivo = 1;
                        break;
                    }
                }
                if (!ehConectivo || novoInicio) {
                    palavra[0] = toupper(palavra[0]);
                }
                strncat(resultado, palavra, TAMANHO_MAXIMO - strlen(resultado) - 1);
                j = 0;
            }
            strncat(resultado, &texto[i], 1);
            novoInicio = (texto[i] == '.' || texto[i] == '!' || texto[i] == '?');
        }
        i++;
    }

    if (j > 0) {
        palavra[j] = '\0';
        ehConectivo = 0;
        for (k = 0; k < num_conectivos; k++) {
            if (strcmp(palavra, conectivos[k]) == 0) {
                ehConectivo = 1;
                break;
            }
        }
        if (!ehConectivo || novoInicio) {
            palavra[0] = toupper(palavra[0]);
        }
        strncat(resultado, palavra, TAMANHO_MAXIMO - strlen(resultado) - 1);
    }

    strncpy(texto, resultado, TAMANHO_MAXIMO - 1);
    texto[TAMANHO_MAXIMO - 1] = '\0';
}

/* Função para exibir uma animação de carregamento */
void visualizacao_texto() {
    int i;

    system("cls");

    for (i = 1; i < 4; i++) {
        printf("%d ...\n", i);
        sleep(1);
    }
    printf("\n\n-=-=-=-=-=-=-=-=-RESULTADO-=-=-=-=-=-=-=-=-=-=\n\n");
}

/* Função principal */
int main() {
    char texto[TAMANHO_MAXIMO];
    char opcao;

    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    do {
        do {
            printf("Digite uma string (até 100 caracteres):\n");
            printf("Somente letras (não acentuadas!) e espaços são permitidos.\n");

            fgets(texto, sizeof(texto), stdin);

            if (strlen(texto) == TAMANHO_MAXIMO - 1) {
                printf("Erro: A string excede o tamanho máximo permitido (100 caracteres).\n");
                printf("Será truncada para 100 caracteres automaticamente!\n");
                limparBuffer();
                continue;
            }

        } while (valida_string(texto) == 0);

        texto[strcspn(texto, "\n")] = '\0';

        salvarTextoOriginal(texto);

        do {
            printf("\nEscolha uma opção de conversão:\n");
            printf("[ 1 ] - TODAS AS LETRAS MAIÚSCULAS\n");
            printf("[ 2 ] - todas as letras minúsculas\n");
            printf("[ 3 ] - Inversão de caixa\n");
            printf("[ 4 ] - Apenas a primeira letra da frase em maiúscula\n");
            printf("[ 5 ] - Primeira Letra de Cada Palavra em Maiúscula, Exceto Conectivos\n");
            printf("[ 6 ] - Mostrar a frase original\n");
            printf("[ 0 ] - Nova palavra / Sair\n");
            printf("Opção: ");
            scanf(" %c", &opcao);

            limparBuffer();

            carregarTextoOriginal(texto);

            switch (opcao) {
            case '1':
                paraMaiusculas(texto);
                visualizacao_texto();
                printf(">>> %s\n", texto);
                break;
            case '2':
                paraMinusculas(texto);
                visualizacao_texto();
                printf(">>> %s\n", texto);
                break;
            case '3':
                inverterCaixa(texto);
                visualizacao_texto();
                printf(">>> %s\n", texto);
                break;
            case '4':
                primeiraLetraMaiuscula(texto);
                visualizacao_texto();
                printf(">>> %s\n", texto);
                break;
            case '5':
                capitalizarPalavras(texto);
                visualizacao_texto();
                printf(">>> %s\n", texto);
                break;
            case '6':
                carregarTextoOriginal(texto);
                printf("Texto original: %s\n", texto);
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
            }
        } while (opcao != '0');

        printf("\nDeseja converter uma nova string? (s/n): ");
        scanf(" %c", &opcao);
        limparBuffer();
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
