/* nome: joel anderson rodrigues */
/* matricula: 571518 */
/* questão: 10 */
/* data: 15/01/2025 */
/* ambiente: linux */
/* ferramenta: neovim */
/* versão compilador: 14.2.1 */

/* Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X e Y). */
/* Em seguida, declare e leia do teclado um ponto e exiba a distância dele até a origem das */
/* coordenadas, isto é, a posição (0,0). */

#include <math.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
} Ponto;

int main() {
    Ponto ponto;

    printf("Digite as coordenadas do ponto (X Y): ");
    scanf("%f %f", &ponto.x, &ponto.y);

    float distancia = sqrt(ponto.x * ponto.x + ponto.y * ponto.y);

    printf("A distância do ponto (%.2f, %.2f) até a origem (0, 0) é: %.2f\n", ponto.x, ponto.y, distancia);
    return 0;
}
