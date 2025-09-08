## 1) Fazer um programa em C ou C++ que preencha um vetor de string com n nomes; exiba-os
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Quantos nomes deseja cadastrar? ";
    cin >> n;
    cin.ignore(); // limpar buffer

    vector<string> nomes(n);

    for (int i = 0; i < n; i++) {
        cout << "Digite o nome " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    cout << "\nNomes cadastrados:\n";
    for (string nome : nomes) {
        cout << nome << endl;
    }

    return 0;
}

```

## 2) A partir do programa anterior, fazer uma rotina que pesquise um nome ou parte do nome entre os nomes cadastrados no vetor de nomes
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Quantos nomes deseja cadastrar? ";
    cin >> n;
    cin.ignore();

    vector<string> nomes(n);

    for (int i = 0; i < n; i++) {
        cout << "Digite o nome " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    string busca;
    cout << "\nDigite um nome ou parte do nome para pesquisar: ";
    getline(cin, busca);

    cout << "\nResultados da pesquisa:\n";
    bool encontrado = false;
    for (string nome : nomes) {
        if (nome.find(busca) != string::npos) {
            cout << nome << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "Nenhum nome encontrado!\n";
    }

    return 0;
}

```

## 3) A partir do programa anterior, pesquise o método de ordenação da bolha ou bubble sort, e aplique no vetor de nomes do código anterior, exibindo os nomes cadastrados.
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubbleSort(vector<string> &nomes) {
    int n = nomes.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nomes[j] > nomes[j + 1]) {
                swap(nomes[j], nomes[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Quantos nomes deseja cadastrar? ";
    cin >> n;
    cin.ignore();

    vector<string> nomes(n);

    for (int i = 0; i < n; i++) {
        cout << "Digite o nome " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    bubbleSort(nomes);

    cout << "\nNomes ordenados:\n";
    for (string nome : nomes) {
        cout << nome << endl;
    }

    return 0;
}

```

## 4) Tendo como base o menu criado para os códigos anteriores, faça um programa que receba dados de glicemia de um paciente diabetico; calcule e exiba a média da glicemia; calcule e exiba e mediana da glicemia; exiba todos os valores cadastrados
* Menu
* 1 - Cadastrar dados glicemicos (45 a 450)
* 2 - Mostrar dados glicemicos
* 3 - Calcular e exibir media
* 4 - Calcular e exibir mediana
* 5 - Sair
* Opcao:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double calcularMedia(const vector<int>& dados) {
    double soma = 0;
    for (int valor : dados) soma += valor;
    return soma / dados.size();
}

double calcularMediana(vector<int> dados) {
    sort(dados.begin(), dados.end());
    int n = dados.size();
    if (n % 2 == 0)
        return (dados[n/2 - 1] + dados[n/2]) / 2.0;
    else
        return dados[n/2];
}

int main() {
    vector<int> glicemia;
    int opcao;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1 - Cadastrar dados glicemicos (45 a 450)\n";
        cout << "2 - Mostrar dados glicemicos\n";
        cout << "3 - Calcular e exibir media\n";
        cout << "4 - Calcular e exibir mediana\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int valor;
            cout << "Digite o valor da glicemia: ";
            cin >> valor;
            if (valor >= 45 && valor <= 450) {
                glicemia.push_back(valor);
                cout << "Valor cadastrado com sucesso!\n";
            } else {
                cout << "Valor invalido! Deve estar entre 45 e 450.\n";
            }
        }
        else if (opcao == 2) {
            cout << "\nValores cadastrados:\n";
            for (int v : glicemia) cout << v << " ";
            cout << endl;
        }
        else if (opcao == 3) {
            if (!glicemia.empty())
                cout << "Media: " << calcularMedia(glicemia) << endl;
            else
                cout << "Nenhum dado cadastrado!\n";
        }
        else if (opcao == 4) {
            if (!glicemia.empty())
                cout << "Mediana: " << calcularMediana(glicemia) << endl;
            else
                cout << "Nenhum dado cadastrado!\n";
        }
        else if (opcao == 5) {
            cout << "Encerrando o programa...\n";
        }
        else {
            cout << "Opcao invalida!\n";
        }

    } while (opcao != 5);

    return 0;
}

```
