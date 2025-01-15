#include <math.h>
#include <stdio.h>
#include <string.h>

int valida_triangulo(float lado1, float lado2, float lado3) {
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
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

float calcula_base(float lado1, float lado2, float lado3) {
    float maior = lado1;

    if (lado2 > maior) {
        maior = lado2;
    }

    if (lado3 > maior) {
        maior = lado3;
    }

    return maior;
}

float calcula_base_isosceles(float lado1, float lado2, float lado3) {
    float base;
    if (lado1 != lado2 && lado1 != lado3) {
        base = lado1;
    } else if (lado2 != lado1 && lado2 != lado3) {
        base = lado2;
    } else {
        base = lado3;
    }
    return base;
}

void area_perimetro_equilatero(float numeros[2], float lado1, float lado2, float lado3) {
    float base, altura;

    base = calcula_base(lado1, lado2, lado3);
    altura = lado1;

    numeros[0] = (pow(base, 2) * pow(3.0, 0.5)) / 4;
    numeros[1] = base * 3;
}

void area_perimetro_isosceles(float numeros[2], float lado1, float lado2, float lado3) {
    float base, altura;
    float aux;

    base = calcula_base_isosceles(lado1, lado2, lado3);
    altura = sqrt(pow(lado1, 2) - pow(base / 2, 2));

    numeros[0] = (base * altura) / 2;
    aux = sqrt(pow(altura, 2) + pow(base / 2, 2));
    numeros[1] = (2 * aux) + base;
}

void area_perimetro_escaleno(float numeros[2], float lado1, float lado2, float lado3) {
    float base, altura;
    float aux;

    float s = s = (lado1 + lado2 + lado3) / 2;
    aux = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    base = calcula_base(lado1, lado2, lado3);
    altura = (2 * aux) / base;

    numeros[0] = (base * altura) / 2;
    numeros[1] = lado1 + lado2 + lado3;
}
