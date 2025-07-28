#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Semeadora
    
    int numeroSorteado = rand() % 100; // Sorteando um número entre e 100
    printf("%d\n", numeroSorteado);
    
    return 1;
}