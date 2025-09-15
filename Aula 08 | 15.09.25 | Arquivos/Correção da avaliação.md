# Questão 1
```cpp
#include <iostream>

using namespace std;

int main() {
    int vetor[15];

    for (int i = 0; i < 15; i++) {
        vetor[i] = -1;
    }

    return 1;
}
```

# Questão 2
```cpp
#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string nome;
    int matricula;
} Aluno;

int main() {

    Aluno turma[20]; //vetor turma tem para cada posicao um elemento do tipo Aluno

    turma[0].nome = "Maria";
    turma[0].matricula = 123;
    
    return 1;
}
```

# Questão 3
```cpp
#include <iostream>
#include <ctime>
#include <cstdlib>


#define TAM 5

using namespace std;

int funcaoMaiorValor(int vetor[], int n) {
    int maior = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main() {
    int vetor[TAM];

    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 40;
        cout << "valor sorteado...." << vetor[i] << endl;
    }

    int maiorValor = funcaoMaiorValor(vetor, TAM);//utilidade é que a função executa somente uma operação, que é localizar o maior

    cout << "O maior valor do vetor eh..." << maiorValor << endl;

    return 1;
}
```

# Questão 4
```cpp
#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string nome;
    int matricula;
} Aluno;

//métodos com retorno, ou funções, ao finalizar suas operações, um valor é devolvido ao processo que o chamou

//métodos sem retorno, ou procedimentos, ao finalizar suas operações NADA é devolvido ao processo que o chamou


void popular(Aluno vetor[], int n){

}

void exibir(Aluno vetor[], int n) {
    
}

int main() {

    Aluno turma[20]; //vetor turma tem para cada posicao um elemento do tipo Aluno

    popular(turma, 20);
    exibir(turma, 20);
    
    return 1;
}
```

# Questão 5
```cpp
#include <iostream>
#define TAM 10
using namespace std;

void lerVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Digite um numero inteiro: ";
        cin >> vetor[i];
    }
}

int somarVetor(int vetor[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += vetor[i]; //total = total + vetor[i]
    }
    return total;
}


int main() {
    int vetor[TAM];

    lerVetor(vetor, TAM);
    int soma = somarVetor(vetor, TAM);

    cout << "A soma de todos os elementos eh: " << soma << endl;
    return 1;
}
```

# Questão 6
```cpp
#include <iostream>
#define TAM 10
using namespace std;

void lerVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Digite um numero inteiro: ";
        cin >> vetor[i];
    }
}


bool estaContido(int valor, int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (valor == vetor[i]) {
            return true;
        }
    }
    //sai do for e olhei todos e nao encontrei o valor, logo
    return false;
}

int main() {
    int vetor[TAM];
    int numeroPesquisa;

    lerVetor(vetor, TAM);
    
    cout << "Digite um valor inteiro para pesquisar no vetor: ";
    cin >> numeroPesquisa;

    if (estaContido(numeroPesquisa, vetor, TAM)) {
        cout << "Valor localizado no vetor....\n";
    } else {
        cout << "Valor NAO localizado no vetor....\n";
    }

    return 1;
}
```

# Questão 7
```cpp
#include <iostream>
#include <string>
#define TAM 5

using namespace std;

typedef struct {
    string nome;
    int matricula;
} Aluno;

void lerDadosAlunos(Aluno vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, vetor[i].nome);

        cout << "Matricula: ";
        cin >>vetor[i].matricula;
    }
}

void exibirDadosAlunos(Aluno vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: " << vetor[i].nome << ". Matricula: " << vetor[i].matricula << endl;
    }
}

int main() {

    Aluno vetor[5]; //vetor turma tem para cada posicao um elemento do tipo Aluno

    lerDadosAlunos(vetor, TAM);
    exibirDadosAlunos(vetor, TAM);
    
    return 1;
}
```

# Questão 8
```cpp
#include <iostream>
#include <string>
#define TAM 5

using namespace std;

typedef struct {
    string nome;
    int matricula;
} Aluno;

void lerDadosAlunos(Aluno vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, vetor[i].nome);

        cout << "Matricula: ";
        cin >>vetor[i].matricula;
    }
}

void exibirDadosAlunos(Aluno vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: " << vetor[i].nome << ". Matricula: " << vetor[i].matricula << endl;
    }
}

int qualPosicao(int matricula, Aluno vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (matricula == vetor[i].matricula) {
            return i;
        }
    }
    //se sai do for, pq olhei todos os alunos e nao bateu a matricula de busca, logo
    return -1;
}

int main() {

    Aluno vetor[TAM]; //vetor turma tem para cada posicao um elemento do tipo Aluno

    lerDadosAlunos(vetor, TAM);
    exibirDadosAlunos(vetor, TAM);

    int matriculaPesquisa;
    cout << "Digite uma matricula de pesquisa: ";
    cin >> matriculaPesquisa;

    int posicaoLocalizada = qualPosicao(matriculaPesquisa, vetor, TAM);
    cout << "O usuario dessa matricula esta na posicao ... " << posicaoLocalizada << endl;
    
    return 1;
}
```
