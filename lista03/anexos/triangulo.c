// o seguinte codigo foi feito pra ser o mais complexo possivel pois estou aprendendo ;)
// Desnesseçariamente comprexo pra caraio mas
// ficou legal ;)
// totalmente overkill

#include "calculos.h"

int main() {
    float lado1, lado2, lado3;
    float numeros[2];

    printf("Digite o valor do lado1: ");
    scanf("%f", &lado1);

    printf("Digite o valor do lado2: ");
    scanf("%f", &lado2);

    printf("Digite o valor do lado3: ");
    scanf("%f", &lado3);

    const char *tipo = tipo_triangulo(lado1, lado2, lado3);

    if (strcmp(tipo, "Equilatero") == 0) {
        area_perimetro_equilatero(numeros, lado1, lado2, lado3);

        printf("\narea %f\nperimetro %f", numeros[0], numeros[1]);

    } else if (strcmp(tipo, "Isosceles") == 0) {
        area_perimetro_isosceles(numeros, lado1, lado2, lado3);

        printf("\narea %f\nperimetro %f", numeros[0], numeros[1]);

    } else if (strcmp(tipo, "Escaleno") == 0) {
        area_perimetro_escaleno(numeros, lado1, lado2, lado3);

        printf("\narea %f\nperimetro %f", numeros[0], numeros[1]);

    } else {
        printf("O triângulo é inválido.\n");
    }

    return 0;
}
