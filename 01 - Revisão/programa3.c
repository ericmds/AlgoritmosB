#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int idade;
    int tempoSono;

    printf("Informe sua idade: ");
    scanf("%d", &idade);

    tempoSono = (int)idade/3;

    printf("Você já dormiu %d anos\n", tempoSono);

    return 1;
}