# Exercícios preparatórios para arquivos

### 1 - Construa um programa (com módulo/método) que leia n nomes completos de pessoas e os exiba na tela
```cpp
#include <iostream>
#include <string>

using namespace std;

#define N 5

void lerNomes(string vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, vetor[i]);
    }
}

void exibirNomes(string vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: " << vetor[i] << endl;
    }
}

void ordenarNomes(string vetor[], int n) {
    string tmp;
    bool houveTroca;

    do {
        houveTroca = false;
        for (int i = 0; i < n-1; i++) {
            if (vetor[i] > vetor[i+1]) {
                houveTroca = true;
                tmp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = tmp;
            }
        }
    } while (houveTroca);
}

int main() {
    string nomes[N];

    // Rotina para ler/receber nomes completos
    lerNomes(nomes, N);

    // Rotina para ordenar nomes com bubble sort
    ordenarNomes(nomes, N);

    // Rotina para exibir os nomes completos
    exibirNomes(nomes, N);

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

using namespace std;

#define N 3

typedef struct {
    string nomeCompleto;
    string sobrenome;
} Pessoa;

string extrairSobrenome(string nome) {
    string sobrenome;
    
    size_t posicao = nome.find_last_of(' ');

    if (posicao != string::npos) {
        sobrenome = nome.substr(posicao + 1);
    } else {
        sobrenome = nome;
    }

    return sobrenome;
}

void lerNomes(Pessoa vetor[], int n) {
    string nomeCompleto;
    string sobrenome;
    
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, nomeCompleto);
        
        sobrenome = extrairSobrenome(nomeCompleto);

        vetor[i].nomeCompleto = nomeCompleto;
        vetor[i].sobrenome = sobrenome;
    }
}

void exibirNomes(Pessoa vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome completo: " << vetor[i].nomeCompleto << ". Sobrenome: " << vetor[i].sobrenome << endl;
    }
}

int main() {
    Pessoa pessoas[N];

    // Rotina para ler/receber nomes completos
    lerNomes(pessoas, N);

    // Rotina para exibir os nomes completos
    exibirNomes(pessoas, N);

    return 0;
}
```

### 3 - Construa um programa (com módulo/método) que leia n nomes de pessoas, armazena em um vetor de nomes e os exiba na tela. Porém, é necessário ao lado do nome mostrar quantos caractares tem esse nome
```cpp
#include <iostream>
#include <string>

using namespace std;

#define N 5

void lerNomes(string vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, vetor[i]);
    }
}

void exibirNomes(string vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: " << vetor[i] << ". Tamanho: " << vetor[i].size() << " caracteres" << endl;
    }
}

void ordenarNomes(string vetor[], int n) {
    string tmp;
    bool houveTroca;

    do {
        houveTroca = false;
        for (int i = 0; i < n-1; i++) {
            if (vetor[i] > vetor[i+1]) {
                houveTroca = true;
                tmp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = tmp;
            }
        }
    } while (houveTroca);
}

int main() {
    string nomes[N];

    // Rotina para ler/receber nomes completos
    lerNomes(nomes, N);

    // Rotina para ordenar nomes com bubble sort
    ordenarNomes(nomes, N);

    // Rotina para exibir os nomes completos
    exibirNomes(nomes, N);

    return 0;
}
```
