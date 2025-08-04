# Exemplo 1.c
```c
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
 
int main() {
    printf("Exemplo de vetor de numeros inteiros\n\n");
    int numero;
    int vetor[TAM];
 
   
    // Rotina que o usuario digita TAM numeros inteiros
    for (int i = 0; i < TAM; i++) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);
 
        vetor[i] = numero;
    }
 
    // Rotina que o programa exibe os numeros inteiros um depois do outro
    printf("Numeros: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d\t", vetor[i]);
    }
    printf("\n");
 
 
    return 1;
}
```

# Exemplo 1.cpp
```cpp
#include <iostream>
#define TAM 5
 
using namespace std;
 
int main() {
    cout << "Exemplo de vetor de numeros inteiros\n\n";
    int numero;
    int vetor[TAM];
 
   
    //rotina que o usuario digita TAM numeros inteiros
    for (int i = 0; i < TAM; i++) {
        cout << "Digite um numero inteiro: ";
        cin >> numero;        
 
        vetor[i] = numero;
    }
 
    //rotina que o programa exibe os numeros inteiros um depois do outro
    cout << "Numeros: ";
    for (int i = 0; i < TAM; i++) {
        cout << vetor[i] << "\t";
    }
   
    cout << "\n";
 
 
    return 1;
}
```
