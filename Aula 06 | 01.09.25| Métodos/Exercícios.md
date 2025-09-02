# Exercícios sobre métodos

### 1) Fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). O método deve contar quantas vezes a letra aparece na palavra e exibir essa quantidade
```cpp
#include <iostream>
#include <string>

using namespace std;

int encontrarLetras(string frase, char letra) {
    int contarLetras = 0;

    for (int i = 0; i < frase.size(); i++) {
        if (frase[i] == letra) {
            contarLetras++;
        }
    }

    return contarLetras;
}

int main() {
    string frase;
    char letra;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Digite uma letra para contar quantas vezes ela aparece na frase: ";
    cin >> letra;

    int total = encontrarLetras(frase, letra);

    cout << "A letra '" << letra << "' aparece " << total << "x na frase \"" << frase << "\"." << endl;

    return 0;
}
```

### 2) Fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas
```cpp

```

### 3) Fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). O método deve contar quantas vezes a letra aparece na palavra e exibir essa quantidade
```cpp
#include <iostream>
#include <string>

using namespace std;

int contarVogais(string frase) {
    int totalVogais = 0;

    for (int i = 0; i < frase.size(); i++) {
        char c = frase[i];
        if (c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c == 'U') {
            totalVogais++;
        }
    }

    return totalVogais;
}

int contarConsoantes(string frase) {
    int totalConsoantes = 0;

    for (int i = 0; i < frase.size(); i++) {
        char c = frase[i];
        if (isalpha(c) && !(c == 'a' || c == 'e' || c == 'i'|| c == 'o' || c == 'u' ||
                            c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c == 'U')) {
            totalConsoantes++;
        }
    }

    return totalConsoantes;
}

int main() {
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Quantidade de vogais na frase: " << contarVogais(frase) << endl;       // corrigido
    cout << "Quantidade de consoantes na frase: " << contarConsoantes(frase) << endl; // corrigido

    return 0;
}
```

### 4) Fazer um programa que tenha um método que receba uma frase e retorne essa frase totalmente em maiúscula
```cpp

```

### 5) Fazer um programa que tenha um método que receba um vetor de números inteiros, o tamanho desse vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado
```cpp

```

### 6) Fazer um programa que tenha um método que receba um nome completo e retorne o primeiro nome desse nome completo
```cpp

```
