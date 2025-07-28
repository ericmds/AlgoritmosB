/* Pedir um número x e um número y e informar em qual quadrante eles se encontram */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;

    printf("Informe o valor do x: ");
    scanf("%d", &x);
    printf("Informe o valor do y: ");
    scanf("%d", &y);

    if(x > 0 && y > 0) {
        printf("O ponto esta no primeiro quadrante");
    }
    if(x < 0 && y > 0) {
        printf("O ponto esta no segundo quuadrante");
    }
    if(x < 0 && y < 0) {
        printf("O ponto esta no terceiro quadrante");
    }
    if(x > 0 && y < 0) {
        printf("O ponto está no quarto quadrante");
    }
    if(x == 0 && y == 0) {
        printf("O ponto está na origem");
    }
    if(x != 0 && y == 0) {
        printf("O ponto esta no ponto x");
    }
    if(x == 0 && y != 0) {
        printf("O ponto esta no ponto y");
    }

    return 1;
}