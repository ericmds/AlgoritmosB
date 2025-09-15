#include <iostream>
#include <string>

#define TAM 2

using namespace std;

typedef struct {
    string nomeCompleto;
    string sobrenome;
} Pessoa;

string extrairSobrenome(string nomeCompleto) {
    size_t pos = nomeCompleto.find_last_of(' ');
    if(pos == string::npos) {
        return nomeCompleto;
    } else {
        return nomeCompleto.substr(pos + 1);
    }
}

void lerNomes(Pessoa vetor[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Digite um nome completo: ";
        getline(cin, vetor[i].nomeCompleto);
        vetor[i].sobrenome = extrairSobrenome(vetor[i].nomeCompleto);
    }
    cout << "\n";
}

void exibirNomes(Pessoa vetor[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nome completo pessoa " << (i+1) << ": " << vetor[i].nomeCompleto << endl;
        cout << "Somente o sobrenome da pessoa " << (i+1) << ": " << vetor[i].sobrenome << endl;
        cout << "\n";
    }
}


int main() {
    Pessoa vetor[TAM];

    lerNomes(vetor, TAM);
    exibirNomes(vetor, TAM);

    return 0;
}
