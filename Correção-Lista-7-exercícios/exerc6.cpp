#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Funcionario {
    int id;
    string nome;
    float salario;
    int idade;
    int tempoEmpresa;
};

int main() {
    int n;

    do {
        cout << "Digite a quantidade de funcionarios (entre 5 e 50): ";
        cin >> n;
        if (n < 5 || n > 50) {
            cout << "Erro: A quantidade deve estar entre 5 e 50.\n";
        }
    } while (n < 5 || n > 50);

    Funcionario originais[50];
    Funcionario atualizados[50];

    cout << "\n--- Cadastro de Funcionarios ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nFuncionario " << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> originais[i].id;

        cin.ignore();
        cout << "Nome: ";
        getline(cin, originais[i].nome);

        cout << "Salario: R$ ";
        cin >> originais[i].salario;

        cout << "Idade: ";
        cin >> originais[i].idade;

        cout << "Tempo de Empresa (anos): ";
        cin >> originais[i].tempoEmpresa;

        atualizados[i] = originais[i];
    }

    float soma_salarios = 0.0;
    float maior_salario = originais[0].salario;
    float menor_salario = originais[0].salario;

    int qtd_idade_maior_50 = 0;
    int qtd_tempo_maior_10 = 0;

    for (int i = 0; i < n; i++) {
        float sal_atual = originais[i].salario;
        soma_salarios += sal_atual;

        if (sal_atual > maior_salario){
            maior_salario = sal_atual;
        }

        if (sal_atual < menor_salario){
            menor_salario = sal_atual;
        }

        if (originais[i].idade > 50){
            qtd_idade_maior_50++;
        }
        if (originais[i].tempoEmpresa > 10){
            qtd_tempo_maior_10++;
        }
    }

    float media_salarial = soma_salarios / n;


    int qtd_acima_media = 0;
    for (int i = 0; i < n; i++) {
        if (originais[i].salario > media_salarial) {
            qtd_acima_media++;
        }
    }

    for (int i = 0; i < n; i++) {
        float percentual_aumento = 0.0;

        if (atualizados[i].tempoEmpresa < 3) {
            percentual_aumento += 0.05;
        } else if (atualizados[i].tempoEmpresa <= 10) {
            percentual_aumento += 0.10;
        } else {
            percentual_aumento += 0.20;
        }

        if (atualizados[i].idade > 50) {
            percentual_aumento += 0.05;
        }
        if (atualizados[i].salario < media_salarial) {
            percentual_aumento += 0.05;
        }

        atualizados[i].salario += atualizados[i].salario * percentual_aumento;
    }

    // --- EXIBIÇÃO DOS RESULTADOS ---
    cout << fixed << setprecision(2);

    cout << "Media salarial......: R$ " << media_salarial << "\n";
    cout << "Maior salario.......: R$ " << maior_salario << "\n";
    cout << "Menor salario.......: R$ " << menor_salario << "\n";
    cout << "--------------------------------------------\n";
    cout << "Funcionarios com salario acima da media: " << qtd_acima_media << "\n";
    cout << "Funcionarios com mais de 50 anos.......: " << qtd_idade_maior_50 << "\n";
    cout << "Funcionarios com mais de 10 anos de casa: " << qtd_tempo_maior_10 << "\n";


    cout << "--- LISTA ORIGINAL ---\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << originais[i].id
             << " | Nome: " << originais[i].nome
             << " | Salario: R$ " << originais[i].salario << "\n";
    }

    cout << "\n--- LISTA ATUALIZADA (COM REAJUSTES) ---\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << atualizados[i].id
             << " | Nome: " << atualizados[i].nome
             << " | Novo Salario: R$ " << atualizados[i].salario << "\n";
    }

    return 0;
}
