#include <iostream> // <stdio.h>
#include <string>   // <string.h>

#define TAM 5

using namespace std;

// Criando um tipo ou uma estrutura artificial
typedef struct {
    string placa;
    string horaEntrada;
    string horaSaida;
    float valor;
} Carro;

int main() {
    Carro garagem[TAM];
    Carro carro;

    for (int i = 0; i < TAM; i++) {
        do {
            cout << "Placa: ";
            cin >> carro.placa;
            if (carro.placa.size() == 7) {
                break;
            } else {
                cout << "Placa invalida! Redigite...\n";
            }
        } while (true);
        cout << "Hora de entrada: ";
        cin >> carro.horaEntrada;

        garagem[i] = carro;
    }

    cout << "Carros na garagem";
    for (int i = 0; i < TAM; i++) {
        cout << "Placa: " << garagem[i].placa << " | Hora entrada: " << garagem[i].horaEntrada << "\n";
    }

    return 1;
}
