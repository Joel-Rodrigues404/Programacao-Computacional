/* Dados três tamanhos de segmentos de reta a, b e c, se a+b>c e a+c>b e b+c>a, estes */
/* segmentos de reta podem formar um triângulo. Faça um programa que, dados os valores */
/* dos tamanhos dos segmentos de reta a, b e c, verificar / informar se formam (podem */
/* formar) ou não um triângulo. Além disso, se forma um triângulo, classifique o triângulo */
/* como: “Equilátero”, “Isósceles” ou “Escaleno”. */

#include <stdio.h>
#include <string.h>

int valida_triangulo(float lado1, float lado2, float lado3) {
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) &&
        (lado2 + lado3 > lado1)) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

const char *tipo_triangulo(float lado1, float lado2, float lado3) {
    static char triangulo_tipo[11];
    if (valida_triangulo(lado1, lado2, lado3)) {

        if (lado1 == lado2 && lado1 == lado3) {
            strcpy(triangulo_tipo, "Equilatero");
        } else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3) {
            strcpy(triangulo_tipo, "Escaleno");
        } else {
            strcpy(triangulo_tipo, "Isosceles");
        }

        printf("E um triangulo do tipo %s", triangulo_tipo);
    } else {
        printf("Não e triangulo\n");
    }
    return triangulo_tipo;
}

int main() {
    float lado1, lado2, lado3;
    float numeros[2];

    printf("Digite o valor do lado1: ");
    scanf("%f", &lado1);

    printf("Digite o valor do lado2: ");
    scanf("%f", &lado2);

    printf("Digite o valor do lado3: ");
    scanf("%f", &lado3);

    tipo_triangulo(lado1, lado2, lado3);

    return 0;
}
