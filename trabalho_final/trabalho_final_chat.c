#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILE_NAME "texto_original.txt"

// Lista de conectivos que devem permanecer minúsculos
const char *conectivos[] = {
    "de", "do", "dos", "da", "das", "a", "as", "o", "os", "ao", "aos",
    "no", "nos", "na", "nas", "em", "por", "e", "sobre", "com", "até",
    "após", "contra", "desde", "entre", "para", "sem", "sob", "nem",
    "que", "se", "mas", "ainda", "assim"};
const int num_conectivos = sizeof(conectivos) / sizeof(conectivos[0]);

// Função para salvar o texto original em um arquivo
void salvarTextoOriginal(const char *texto) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL) {
        fprintf(file, "%s", texto);
        fclose(file);
    } else {
        printf("Erro ao salvar o arquivo.\n");
    }
}

// Função para carregar o texto original do arquivo
void carregarTextoOriginal(char *texto) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL) {
        fgets(texto, MAX_LENGTH, file);
        fclose(file);
    } else {
        printf("Erro ao carregar o arquivo.\n");
    }
}

// Converter toda a string para maiúsculas
void paraMaiusculas(char *texto) {
    for (int i = 0; texto[i]; i++) {
        texto[i] = toupper(texto[i]);
    }
}

// Converter toda a string para minúsculas
void paraMinusculas(char *texto) {
    for (int i = 0; texto[i]; i++) {
        texto[i] = tolower(texto[i]);
    }
}

// Inverter a caixa de cada caractere
void inverterCaixa(char *texto) {
    for (int i = 0; texto[i]; i++) {
        if (isupper(texto[i]))
            texto[i] = tolower(texto[i]);
        else if (islower(texto[i]))
            texto[i] = toupper(texto[i]);
    }
}

// Apenas a primeira letra da frase em maiúscula
void primeiraLetraMaiuscula(char *texto) {
    int i = 0;
    while (texto[i] == ' ')
        i++; // Ignora espaços iniciais

    if (texto[i] != '\0') {
        texto[i] = toupper(texto[i]);
    }
}

// Primeira letra de cada palavra em maiúscula, exceto conectivos
void capitalizarPalavras(char *texto) {
    int novoInicio = 1; // Indica se a próxima letra deve ser maiúscula
    char palavra[MAX_LENGTH], resultado[MAX_LENGTH] = "";
    int i = 0, j = 0;

    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            palavra[j++] = tolower(texto[i]); // Armazena a palavra em minúsculas
        } else {
            if (j > 0) {
                palavra[j] = '\0';
                int ehConectivo = 0;
                for (int k = 0; k < num_conectivos; k++) {
                    if (strcmp(palavra, conectivos[k]) == 0) {
                        ehConectivo = 1;
                        break;
                    }
                }
                if (!ehConectivo || novoInicio) {
                    palavra[0] = toupper(palavra[0]); // Torna a primeira letra maiúscula se necessário
                }
                strcat(resultado, palavra);
                j = 0;
            }
            strncat(resultado, &texto[i], 1);
            novoInicio = (texto[i] == '.' || texto[i] == '!' || texto[i] == '?');
        }
        i++;
    }
    strcpy(texto, resultado);
}

int main() {
    char texto[MAX_LENGTH];
    char opcao;

    do {
        printf("Digite uma string (até 100 caracteres):\n");
        fgets(texto, MAX_LENGTH, stdin);
        texto[strcspn(texto, "\n")] = '\0'; // Remove o caractere de nova linha

        salvarTextoOriginal(texto);

        do {
            printf("\nEscolha uma opção de conversão:\n");
            printf("1 - TODAS AS LETRAS MAIÚSCULAS\n");
            printf("2 - todas as letras minúsculas\n");
            printf("3 - Inversão de caixa\n");
            printf("4 - Apenas a primeira letra da frase em maiúscula\n");
            printf("5 - Primeira letra de cada palavra em maiúscula, exceto conectivos\n");
            printf("6 - Mostrar a frase original\n");
            printf("0 - Sair\n");
            printf("Opção: ");
            scanf(" %c", &opcao);
            getchar(); // Captura o ENTER deixado no buffer

            carregarTextoOriginal(texto); // Sempre começa com a versão original

            switch (opcao) {
            case '1':
                paraMaiusculas(texto);
                printf("Resultado: %s\n", texto);
                break;
            case '2':
                paraMinusculas(texto);
                printf("Resultado: %s\n", texto);
                break;
            case '3':
                inverterCaixa(texto);
                printf("Resultado: %s\n", texto);
                break;
            case '4':
                primeiraLetraMaiuscula(texto);
                printf("Resultado: %s\n", texto);
                break;
            case '5':
                capitalizarPalavras(texto);
                printf("Resultado: %s\n", texto);
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
        getchar(); // Captura o ENTER deixado no buffer
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
