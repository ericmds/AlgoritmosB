## 1. Fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). O método deve contar quantas vezes a letra aparece na palavra e exibir essa quantidade
```cpp
#include <iostream>
#include <string>
using namespace std;

int contarLetra(string palavra, char letra) {
    int cont = 0;
    for (char c : palavra) {
        if (tolower(c) == tolower(letra)) { // ignora maiúsculas/minúsculas
            cont++;
        }
    }
    return cont;
}

int main() {
    string palavra;
    char letra;
    cout << "Digite uma palavra: ";
    cin >> palavra;
    cout << "Digite uma letra: ";
    cin >> letra;

    cout << "A letra '" << letra << "' aparece " 
         << contarLetra(palavra, letra) << " vezes.\n";
    return 0;
}
```

## 2. Fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas
```cpp
#include <iostream>
#include <string>
using namespace std;

bool dataValida(string diaStr, string mesStr, string anoStr) {
    int dia = stoi(diaStr);
    int mes = stoi(mesStr);
    int ano = stoi(anoStr);

    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) return false;

    int diasMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    // ano bissexto
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        diasMes[2] = 29;

    if (dia > diasMes[mes]) return false;
    return true;
}

int main() {
    string d, m, a;
    cout << "Digite o dia: ";
    cin >> d;
    cout << "Digite o mes: ";
    cin >> m;
    cout << "Digite o ano: ";
    cin >> a;

    if (dataValida(d, m, a))
        cout << "DATA VALIDA\n";
    else
        cout << "DATA INVALIDA\n";

    return 0;
}
```

## 3. Fazer um programa que tenha um método que receba uma frase e retorne a quantidade de vogais presentes na frase
```cpp
#include <iostream>
#include <string>
using namespace std;

int contarVogais(string frase) {
    int cont = 0;
    for (char c : frase) {
        char ch = tolower(c);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cont++;
    }
    return cont;
}

int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Quantidade de vogais: " << contarVogais(frase) << "\n";
    return 0;
}
```

## 4. Fazer um programa que tenha um método que receba uma frase e retorne essa frase totalmente em maiúscula
```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string paraMaiuscula(string frase) {
    for (char &c : frase) {
        c = toupper(c);
    }
    return frase;
}

int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Frase em maiusculas: " << paraMaiuscula(frase) << "\n";
    return 0;
}
```

## 5. Fazer um programa que tenha um método que receba um vetor de números inteiros, o tamanho desse vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado
```cpp
#include <iostream>
using namespace std;

bool vetorOrdenado(int v[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1])
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    int v[n];
    cout << "Digite os elementos: ";
    for (int i = 0; i < n; i++) cin >> v[i];

    if (vetorOrdenado(v, n))
        cout << "O vetor esta ordenado.\n";
    else
        cout << "O vetor NAO esta ordenado.\n";
    return 0;
}
```

## 6. Fazer um programa que tenha um método que receba um nome completo e retorne o primeiro nome desse nome completo
```cpp
#include <iostream>
#include <string>
using namespace std;

string primeiroNome(string nomeCompleto) {
    int pos = nomeCompleto.find(" ");
    if (pos == string::npos) return nomeCompleto;
    return nomeCompleto.substr(0, pos);
}

int main() {
    string nome;
    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "Primeiro nome: " << primeiroNome(nome) << "\n";
    return 0;
}
```
