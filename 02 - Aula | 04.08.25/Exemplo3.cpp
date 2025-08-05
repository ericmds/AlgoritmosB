#include <iostream>
#include <string>
#define TAM 5

using namespace std;

int main() {
    cout << "Exemplo de vetor de placa que sao strings\n\n";
    string nome;
    string vetorAlunos[TAM];

    // Rotina que o usuario digita o TAM numeros inteiros
    for (int i=0; i < TAM; i++) {
        cout << "Digite um nome: ";
        getline(cin, nome);
        
        // Rotina que insere um nome, se e somente se o nome não estiver no vetor
        vetorAlunos[i] = nome;
    }

    // Rotina que o programa exibe os numeros inteiros um depois do outro
    cout << "Placas: ";
    for (int i = 0; i < TAM; i++) {
        cout << vetorAlunos[i] << "\t";
    }
    cout << "\n";

    return 1;
}
