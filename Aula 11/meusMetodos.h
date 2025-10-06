#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void gravarPessoaBase(string nome, string email, string baseDados) {
    ofstream procuradorArquivo;
    procuradorArquivo.open(baseDados, ios::out | ios::app);

    procuradorArquivo << "\n" << nome << "," << email;

    procuradorArquivo.close();
}

int cadastrarPessoas(Pessoa vetor[], int tamanho, int qtd_pessoas, string baseDados) {
    if (tamanho == qtd_pessoas) {
        cout << "Estrutura de dados lotada!" << endl;
        
        return qtd_pessoas;
    }

    string nome;
    string email;

    cout << "Informe os dados das pessoas para cadastrar" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    fflush(stdin);
    cout << "Email: ";
    cin >> email;
    fflush(stdin);

    // Validar se o nom e o email ja estão no vetor

    vetor[qtd_pessoas].nome = nome;
    vetor[qtd_pessoas].email = nome;
    qtd_pessoas ++;

    // Gravar a pessoas (nome,email) na base
    gravarPessoaBase(nome, email, baseDados);

    return qtd_pessoas;
}

void listarPessoas(Pessoa vetor[], int qtd_pessoas) {
    cout << "Listando pessoas..." << endl;

    for (int i = 0; i < qtd_pessoas; i++) {
        cout << "Nome: " << vetor[i].nome << ". Email: " << vetor[i].email << endl;
    }

    cout << "___________________________\n";
    cout << "Total de registros: " << qtd_pessoas << endl;
}

void menu(Pessoa vetor[], int tamanho, int qtd_pessoas, string baseDados) {
    int opcao;

    do {
        system("cls");
        cout << "MENU" << endl;
        cout << "1 - Listar pessoas" << endl;
        cout << "2 - Cadastrar pessoas" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao) {
        case 1:
            listarPessoas(vetor, qtd_pessoas);
            break;
        
        case 2:
            cout << "Cadastrando pessoas..." << endl;
            qtd_pessoas = cadastrarPessoas(vetor, tamanho, qtd_pessoas, baseDados);
            
            break;

        case 3:
            cout << "Saindo do programa..."  << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
            break;
        }

        system("pause");
    } while (opcao != 3);
}

void split(string vetor[], string str, string deli = " ")
{
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
}

int conectarBase(string baseDados, Pessoa vetor[], int tamanho) {
    int qtd_pessoas = 0;
    ifstream procuradorArquivo; // tipo de arquivo para leitura
    procuradorArquivo.open(baseDados);

    if (!procuradorArquivo) {
        cout << "Arquivo da base de dados não localizado. Programa encerrado." << endl;
        exit(0);
    }
    if (qtd_pessoas == tamanho) {
        cout << "Vetor lotado. Programa encerrado." << endl;
        exit(0);
    }

    // le o arquivo capturando as pessoas linha a linha
    string linha;
    string vetorLinha[2];
    while (!procuradorArquivo.eof()) {
        getline(procuradorArquivo, linha);        // Lendo a linha inteira -> Alexandre Zamberlan,alexz@ufn.edu.br
        split(vetorLinha, linha, ",");            // Separa a linha em vetor pela ","
        vetor[qtd_pessoas].nome = vetorLinha[0];  // vetorLinha[0] = "Alexandre Zamberlan"
        vetor[qtd_pessoas].email = vetorLinha[1]; // vetorLinha[1] = "alexz@ufn.edu.br"
        qtd_pessoas ++;
    }
    procuradorArquivo.close();
    cout << "Quantidade " << qtd_pessoas << endl;
    return qtd_pessoas;
}
