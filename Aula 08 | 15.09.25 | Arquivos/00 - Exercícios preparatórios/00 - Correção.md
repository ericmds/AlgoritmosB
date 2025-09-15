# Exercícios preparatórios para arquivos

### 1 - Construa um programa (com módulo/método) que leia n nomes completos de pessoas e os exiba na tela
```cpp
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
```

### 2 - Construa um programa (com módulo/método) que leia n nomes completos de pessoas e os adicione em um vetor de n posicoes em que deve ser armazenado o nome completo e o sobrenome. Use a seguinte estrutura

```cpp
typedef struct {
  string nomeCompleto;
  string sobreNome;
} Pessoa;
```
* Dica: será preciso fazer uma função que extraia o sobrenome de um nome completo.
```cpp
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
```

### 3 - Construa um programa (com módulo/método) que leia n nomes de pessoas, armazena em um vetor de nomes e os exiba na tela. Porém, é necessário ao lado do nome mostrar quantos caractares tem esse nome
```cpp
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

int contarCaracteres(string nomeCompleto) {
    return nomeCompleto.length();
}

void exibirNomes(Pessoa vetor[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nome completo pessoa " << (i+1) << ": " << vetor[i].nomeCompleto << endl;
        cout << "Somente o sobrenome da pessoa " << (i+1) << ": " << vetor[i].sobrenome << endl;
        cout << "Quantidade de caracteres: " << contarCaracteres(vetor[i].nomeCompleto) << endl;
        cout << "\n";
    }
}

int main() {
    Pessoa vetor[TAM];

    lerNomes(vetor, TAM);
    exibirNomes(vetor, TAM);

    return 0;
}
```
