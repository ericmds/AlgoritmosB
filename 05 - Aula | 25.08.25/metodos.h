#include <cstdlib>
#include <time.h>
#include <string.h>

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; // Força a saída do método
    }
    
    srand(time(NULL));

    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; // Forcando a saída do método
    }

    cout << frase << endl;
    
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}

void menorElemento(int vetor[], int quantidade, int tamanho) {
    int menor = vetor[0];

    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; // Forcando a saída do método
    }

    for (int i = 1; i < quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
}
