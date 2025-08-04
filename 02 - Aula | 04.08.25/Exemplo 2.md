# Exemplo2.c
```c
#include <stdio.h>
#include <Stdlib.h>
#include <string.h>
#define TAM 5

int main() {
    printf("Exemplo de vetor de placa que sao strings\n\n");
    char placa[7];
    int vetor[TAM][7];

    // Rotina que o usuario digita o TAM numeros inteiros
    for (int i=0; i < TAM; i++) {
        printf("Digite uma placa: ");
        scanf("%s", placa);

        strcpy(vetor[i], placa);
    }

    // Rotina que o programa exibe os numeros inteiros um depois do outro
    printf("Placas: ");
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", vetor[i]);
    }
    printf("\n");

    return 1;
}
```

# Exemplo 2.cpp
```
#include <iostream>
#include <string>
#define TAM 5

using namespace std;

int main() {
    cout << "Exemplo de vetor de placa que sao strings\n\n";
    string placa;
    string vetor[TAM];

    // Rotina que o usuario digita o TAM numeros inteiros
    for (int i=0; i < TAM; i++) {
        cout << "Digite uma placa: ";
        cin >> placa;

        vetor[i] = placa;
    }

    // Rotina que o programa exibe os numeros inteiros um depois do outro
    cout << "Placas: ";
    for (int i = 0; i < TAM; i++) {
        cout << vetor[i] << "\t";
    }
    cout << "\n";

    return 1;
}
```

# Exemplo 2.py
```
print("Exemplo de vetor de placas que sao strings\n\n")
vetor = []
TAM = 5

# Rotina que o usuario digita TAM numeros inteiros
for i in range(TAM):
    placa = input("Digite uma placa: ")
    
    if placa not in vetor:
        vetor.append(placa)
    else:
        print("Placa já cadastrada")    
            
# Rotina que o programa exibe os numeros inteiros um depois do outro
print("Placas: ", end="")
for i in range(TAM):
    print(placa, end=" ")
```
