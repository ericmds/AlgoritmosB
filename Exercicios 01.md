#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // Para manipular data e hora
#include <iomanip> // Para formatar saída

using namespace std;

// Estrutura que representa um filme
struct Filme {
    string titulo;
    string categoria;
    string dataCadastro;
};

// Função para pegar data e hora atuais no formato string
string getDataHoraAtual() {
    time_t agora = time(0);
    tm *tempoLocal = localtime(&agora);

    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y %H:%M:%S", tempoLocal);

    return string(buffer);
}

// Função para cadastrar um novo filme
void cadastrarFilme(vector<Filme> &filmes) {
    Filme f;
    cout << "Digite o titulo do filme: ";
    getline(cin, f.titulo);

    cout << "Digite a categoria (Romance, Ficcao, Terror): ";
    getline(cin, f.categoria);

    f.dataCadastro = getDataHoraAtual();

    filmes.push_back(f);
    cout << "Filme cadastrado com sucesso em " << f.dataCadastro << "!\n\n";
}

// Função para listar todos os filmes
void listarFilmes(const vector<Filme> &filmes) {
    if (filmes.empty()) {
        cout << "Nenhum filme cadastrado.\n\n";
        return;
    }

    cout << "===== LISTA DE FILMES =====\n";
    for (size_t i = 0; i < filmes.size(); i++) {
        cout << i + 1 << ". " << filmes[i].titulo
             << " | Categoria: " << filmes[i].categoria
             << " | Cadastrado em: " << filmes[i].dataCadastro << "\n";
    }
    cout << endl;
}

// Função para pesquisar filmes pelo título
void pesquisarFilme(const vector<Filme> &filmes) {
    if (filmes.empty()) {
        cout << "Nenhum filme cadastrado para pesquisa.\n\n";
        return;
    }

    string termo;
    cout << "Digite parte do titulo do filme: ";
    getline(cin, termo);

    bool encontrado = false;
    cout << "===== RESULTADO DA PESQUISA =====\n";
    for (const auto &f : filmes) {
        if (f.titulo.find(termo) != string::npos) {
            cout << "Titulo: " << f.titulo
                 << " | Categoria: " << f.categoria
                 << " | Cadastrado em: " << f.dataCadastro << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum filme encontrado com esse trecho.\n";
    }
    cout << endl;
}

// Função principal com menu
int main() {
    vector<Filme> filmes;
    int opcao;

    do {
        cout << "===== MENU =====\n";
        cout << "1 - Cadastrar filme\n";
        cout << "2 - Listar filmes\n";
        cout << "3 - Pesquisar por titulo\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Limpar buffer do Enter

        switch (opcao) {
            case 1:
                cadastrarFilme(filmes);
                break;
            case 2:
                listarFilmes(filmes);
                break;
            case 3:
                pesquisarFilme(filmes);
                break;
            case 4:
                cout << "Encerrando programa...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 4);

    return 0;
}
