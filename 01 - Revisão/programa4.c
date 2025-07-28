#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Fazer um programa que sorteie 10 números aleatórios entre 0 e 100 e
armazenando-os em um vetor de amanho 10. Ao final, exibir esses números*/

#define TAM 10

int main() {
    int vetor[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100;
    }

    for (int i = 0; i < TAM; i++) {
        printf("%d\t", vetor[i]);
    }

    printf("\n");

    return 1;
}