#include <iostream>
#include <string>

#define TAM 5

using namespace std;

void lerNomes(string vetor[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Digite um nome completo: ";
        getline(cin, vetor[i]);
    }
}

void exibirNomes(string vetor[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nome " << (i+1) << ": " << vetor[i] << endl;
    }
}

int main() {
    string vetor[TAM];  // Agora o vetor armazena strings

    lerNomes(vetor, TAM);
    exibirNomes(vetor, TAM);

    return 0;
}
