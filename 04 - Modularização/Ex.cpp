#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Paciente {
public:
    string nome;
    string sexo;
    string dataNascimento;
    float altura;
    float peso;

    void cadastrar() {
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Sexo: ";
        getline(cin, sexo);
        cout << "Data de Nascimento (dd/mm/aaaa): ";
        getline(cin, dataNascimento);
        cout << "Altura (m): ";
        cin >> altura;
        cout << "Peso (kg): ";
        cin >> peso;
        cin.ignore();
    }

    void mostrar() {
        cout << "Paciente: " << nome << " | Sexo: " << sexo 
             << " | Nasc: " << dataNascimento
             << " | Altura: " << altura << " | Peso: " << peso << endl;
    }
};

class ProfissionalSaude {
public:
    string nome;
    string cargo;
    string registro;

    void cadastrar() {
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Cargo: ";
        getline(cin, cargo);
        cout << "Registro (CRM/COREN): ";
        getline(cin, registro);
    }

    void mostrar() {
        cout << "Profissional: " << nome << " | Cargo: " << cargo 
             << " | Registro: " << registro << endl;
    }
};

class Unidade {
public:
    string nome;
    string endereco;

    void cadastrar() {
        cout << "Nome da Unidade: ";
        getline(cin, nome);
        cout << "Endereco: ";
        getline(cin, endereco);
    }

    void mostrar() {
        cout << "Unidade: " << nome << " | Endereco: " << endereco << endl;
    }
};

class Triagem {
public:
    bool febre, dores, corisa, vomito;
    int pontuacao;

    Triagem() : febre(false), dores(false), corisa(false), vomito(false), pontuacao(0) {}

    void realizar() {
        char resp;
        cout << "Paciente com febre? (s/n): ";
        cin >> resp; febre = (resp == 's');
        cout << "Paciente com dores musculares? (s/n): ";
        cin >> resp; dores = (resp == 's');
        cout << "Paciente com corisa? (s/n): ";
        cin >> resp; corisa = (resp == 's');
        cout << "Paciente com vomito? (s/n): ";
        cin >> resp; vomito = (resp == 's');

        // Exemplo fictício de pontuação (troque pela tabela do professor)
        pontuacao = 0;
        if (febre) pontuacao += 2;
        if (dores) pontuacao += 1;
        if (corisa) pontuacao += 1;
        if (vomito) pontuacao += 2;

        cout << "Pontuacao final: " << pontuacao << endl;

        if (pontuacao >= 5)
            cout << "Urgencia ALTA! Atendimento imediato.\n";
        else if (pontuacao >= 3)
            cout << "Urgencia MEDIA. Atendimento prioritario.\n";
        else
            cout << "Urgencia BAIXA. Pode aguardar.\n";
    }
};

int main() {
    vector<Paciente> pacientes;
    vector<ProfissionalSaude> profissionais;
    vector<Unidade> unidades;

    int opcao;
    do {
        cout << "\n==== MENU PRINCIPAL ====\n";
        cout << "1 - Cadastrar paciente\n";
        cout << "2 - Cadastrar unidade\n";
        cout << "3 - Cadastrar profissional\n";
        cout << "4 - Realizar triagem\n";
        cout << "5 - Listar cadastros\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case 1: {
                Paciente p;
                p.cadastrar();
                pacientes.push_back(p);
                break;
            }
            case 2: {
                Unidade u;
                u.cadastrar();
                unidades.push_back(u);
                break;
            }
            case 3: {
                ProfissionalSaude ps;
                ps.cadastrar();
                profissionais.push_back(ps);
                break;
            }
            case 4: {
                Triagem t;
                t.realizar();
                break;
            }
            case 5: {
                cout << "\n--- Pacientes ---\n";
                for (auto &p : pacientes) p.mostrar();
                cout << "\n--- Unidades ---\n";
                for (auto &u : unidades) u.mostrar();
                cout << "\n--- Profissionais ---\n";
                for (auto &ps : profissionais) ps.mostrar();
                break;
            }
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}
