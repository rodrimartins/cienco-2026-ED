#include <iostream>
#include <iomanip> // Biblioteca para formatar a saída com casas decimais
#include <cctype>  // Biblioteca para usar a função toupper()

using namespace std;

int main() {
    int idade;
    char doenca_pre, fumante;
    double renda, valor_base = 0.0, valor_final = 0.0;

    cout << "--- Sistema de Calculo de Plano de Saude ---\n";
    cout << "Digite a idade do cliente: ";
    cin >> idade;

    cout << "Possui doencas pre-existentes? (S/N): ";
    cin >> doenca_pre;
    doenca_pre = toupper(doenca_pre); // Converte para maiúscula para evitar erros na digitação

    cout << "E fumante? (S/N): ";
    cin >> fumante;
    fumante = toupper(fumante);

    cout << "Digite a renda mensal: R$ ";
    cin >> renda;

    if (idade <= 18) {
        valor_base = 100.0;
    } else if (idade >= 19 && idade <= 40) {
        valor_base = 180.0;
    } else if (idade >= 41 && idade <= 60) {
        valor_base = 300.0;
    } else {
        valor_base = 500.0;
    }

    valor_final = valor_base;

    if (doenca_pre == 'S') {
        if (idade <= 40) {
            valor_final += valor_base * 0.30;
        } else {
            valor_final += valor_base * 0.50;
        }
    }

    if (fumante == 'S') {
        if (idade <= 50) {
            valor_final += valor_base * 0.20;
        } else {
            valor_final += valor_base * 0.40;
        }
    }

    if (renda < 2000.0) {
        valor_final -= valor_final * 0.20;
    } else if (renda >= 2000.0 && renda <= 5000.0) {
        valor_final -= valor_final * 0.10;
    }

    cout << fixed << setprecision(2); // Fixa a formatação em 2 casas decimais (Ex: 100.00)
    cout << "Valor Base: R$ " << valor_base << endl;
    cout << "Valor Final do Plano: R$ " << valor_final << endl;

    return 0;
}
