# Biblioteca de Funções em C++

## Índice
1. [Strings](#strings)  
2. [Arquivos](#arquivos)  
3. [Vetores](#vetores)  
4. [Datas](#datas)


## Strings

### `split`  
Divide uma string em partes usando um delimitador e preenche um vetor com os pedaços.  
```h
#include <string>
using namespace std;

void split(string vetor[], string str, string deli = " ") {        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
```

### contarVogais
Conta quantas vogais (maiúsculas e minúsculas) há em uma frase.
```h
#include <string>
using namespace std;

int contarVogais(string frase) {
    int totalVogais = 0;
    for (int i = 0; i < frase.size(); i++) {
        if (frase[i]=='A'||frase[i]=='E'||frase[i]=='I'||frase[i]=='O'||frase[i]=='U'||
            frase[i]=='a'||frase[i]=='e'||frase[i]=='i'||frase[i]=='o'||frase[i]=='u') {
            totalVogais++;
        }
    }
    return totalVogais;
}
```

### trocarCaracter
Troca todas as ocorrências de uma letra na frase por @, independentemente de maiúsculas/minúsculas.
```h
#include <string>
using namespace std;

string trocarCaracter(string frase, char letra) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
    return frase;
}

```

### trocarCaracterOrigemDestino
Substitui todas as ocorrências de uma letra (origem) por outra letra (destino), ignorando maiúsculas/minúsculas.
```h
#include <string>
using namespace std;

string trocarCaracterOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
    return frase;
}
```

### contarPalavras
Conta o número de palavras em uma frase usando istringstream.
```h
#include <sstream>
#include <string>
using namespace std;

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    while (stream >> palavra) {
        contagem++;
    }
    return contagem;
}
```

### paraMaiusculo
```h
#include <string>
using namespace std;

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}
```

## Arquivos

### existeArquivo
Verifica se um arquivo com o nome dado existe.
```h
#include <fstream>
#include <string>
using namespace std;

bool existeArquivo(string nomeArquivo) {
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo); 
    if (procuradorArquivo) {
        procuradorArquivo.close();
        return true;
    }
    return false;
}

```

### copiarArquivo2String
Lê um arquivo inteiro e retorna seu conteúdo como uma única string.
```h
#include <fstream>
#include <string>
using namespace std;

string copiarArquivo2String(string nomeArquivo) {
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo);

    string resposta = "";
    string linha;
    while (!procuradorArquivo.eof()) {
        getline(procuradorArquivo, linha);
        resposta += linha + "\n";
    }

    procuradorArquivo.close();
    return resposta;
}
```

### conectarBase (para pessoas)
Abre uma base de dados (arquivo CSV) com nome e email, faz split de cada linha e carrega em um vetor de Pessoa.
```h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int conectarBase(string baseDados, Pessoa vetor[], int tamanho) {
    int qtdPessoas = 0;
    ifstream procuradorArquivo;
    procuradorArquivo.open(baseDados);

    if (!procuradorArquivo) {
        cout << "Arquivo da base de dados não localizado. Programa encerrado." << endl;
        exit(0);
    }
    if (qtdPessoas == tamanho) {
        cout << "Vetor lotado. Programa encerrado." << endl;
        exit(0);
    }

    string linha;
    string vetorLinha[2];
    while (!procuradorArquivo.eof()) {
        getline(procuradorArquivo, linha);
        split(vetorLinha, linha, ",");
        vetor[qtdPessoas].nome = vetorLinha[0];
        vetor[qtdPessoas].email = vetorLinha[1];
        qtdPessoas++;
    }

    procuradorArquivo.close();
    return qtdPessoas;
}
```

### conectarBase (para lista de nomes)
Lê um arquivo de nomes e carrega cada linha em um vetor de strings.
```h
#include <fstream>
#include <string>
using namespace std;

int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho) {
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeBaseDados);

    string linha;
    int quantidadeNomes = 0;
    while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
        getline(procuradorArquivo, linha);
        listaNomes[quantidadeNomes] = linha;
        quantidadeNomes++;
    }

    procuradorArquivo.close();
    return quantidadeNomes;
}
```

## Vetores

### popular
Preenche um vetor de inteiros com valores aleatórios entre 0 e 99.
```h
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}
```

### exibir
Mostra os elementos de um vetor de inteiros, com uma frase de título.
```h
#include <iostream>
using namespace std;

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return;
    }
    cout << frase << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}
```

### menorElemento
Encontra e exibe o menor valor em um vetor de inteiros.
```h
#include <iostream>
using namespace std;

void menorElemento(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return;
    }
    int menor = vetor[0];
    for (int i = 1; i < quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    cout << "Menor elemento.... " << menor << endl;
}
```

## Datas

### escreverSeValida
Verifica se uma data representada por dia, mês e ano é válida e imprime mensagem correspondente.
```h
#include <iostream>
using namespace std;

void escreverSeValida(int dia, int mes, int ano) {
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}
```

### escreverSeValida2
```h
#include <iostream>
#include <string>
using namespace std;

void escreverSeValida2(string data) {
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}
```

### verificarDataValida
Retorna true se a data (string "DD/MM/YYYY") é válida, ou false caso contrário.
```h
#include <string>
using namespace std;

bool verificarDataValida(string data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        return false;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        return false;
    } else if (dia > 29 && mes == 2) {
        return false;
    }
    return true;
}
```
