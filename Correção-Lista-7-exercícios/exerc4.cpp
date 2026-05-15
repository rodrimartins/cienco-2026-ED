#include <iostream>
#include <iomanip> // Para formatar os valores em reais (R$) com duas casas decimais

using namespace std;

int main() {
    int opcao;
    double saldo = 0.00;
    double valor;
    double total_depositado = 0.0;
    double total_sacado = 0.0;
    int num_operacoes = 0;
    double maior_deposito = 0.0;
    double maior_saque = 0.0;

    cout << fixed << setprecision(2);

    do {
        cout << "1 - Deposito\n";
        cout << "2 - Saque\n";
        cout << "3 - Consulta\n";
        cout << "4 - Relatorio Parcial\n";
        cout << "0 - Encerrar sistema\n";
        cout << "-----------------------------------------\n";
        cout << "Escolha uma operacao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor do deposito: R$ ";
                cin >> valor;

                if (valor > 0) {
                    saldo += valor;
                    total_depositado += valor;
                    num_operacoes++;


                    if (valor > maior_deposito) {
                        maior_deposito = valor;
                    }
                    cout << ">>> Deposito realizado com sucesso!\n";
                } else {
                    cout << ">>> Erro: O valor do deposito deve ser positivo.\n";
                }
                break;

            case 2:
                cout << "Digite o valor do saque: R$ ";
                cin >> valor;

                if (valor <= 0) {
                    cout << ">>> Erro: Valor invalido para saque.\n";
                } else if (valor > saldo) {
                    cout << ">>> Erro: Saldo insuficiente!\n";
                } else {
                    if (valor > (saldo * 0.5)) {
                        cout << ">>> AVISO: Saque de alto valor detectado.\n";
                    }

                    saldo -= valor;
                    total_sacado += valor;
                    num_operacoes++;

                    if (valor > maior_saque) {
                        maior_saque = valor;
                    }
                    cout << ">>> Saque realizado com sucesso!\n";
                }
                break;

            case 3:
                cout << "\n>>> SALDO ATUAL: R$ " << saldo << " <<<\n";
                break;

            case 4:
                cout << "\n--- RELATORIO PARCIAL ---\n";
                cout << "Total depositado.........: R$ " << total_depositado << "\n";
                cout << "Total sacado.............: R$ " << total_sacado << "\n";
                cout << "Operacoes realizadas.....: " << num_operacoes << "\n";
                cout << "Maior deposito realizado.: R$ " << maior_deposito << "\n";
                cout << "Maior saque realizado....: R$ " << maior_saque << "\n";
                cout << "-------------------------\n";
                break;

            case 0:
                cout << "\n>>> Encerrando o sistema... Obrigado por utilizar nosso caixa!\n";
                break;

            default:
                cout << ">>> Erro: Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
