#include <iostream>
#include <iomanip> // Para formatar as médias com casas decimais


using namespace std;

int main() {
    int n;

    int qtd_pares = 0, qtd_impares = 0;
    int qtd_positivos = 0, qtd_negativos = 0, qtd_zeros = 0;
    int qtd_mult_3 = 0, qtd_mult_5 = 0, qtd_mult_ambos = 0;
    int maior, menor;
    int soma_pares = 0, soma_impares = 0;

    cout << "--- Analise Completa de Sequencia Numerica ---\n";
    do {
        cout << "Digite a quantidade de numeros (N >= 10): ";
        cin >> n;
        if (n < 10) {
            cout << "Erro: A quantidade deve ser no minimo 10.\n";
        }
    } while (n < 10);

    cout << "\n--- Digite os " << n << " numeros ---\n";
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Numero " << (i + 1) << ": ";
        cin >> num;

        if (i == 0) {
            maior = num;
            menor = num;
        } else {
            if (num > maior){
               maior = num;
            }
            if (num < menor){
                menor = num;
            }
        }

        if (num % 2 == 0) {
            cout << "Par, ";
            qtd_pares++;
            soma_pares += num;
        } else {
            cout << "Impar, ";
            qtd_impares++;
            soma_impares += num;
        }

        if (num > 0) {
            cout << "Positivo, ";
            qtd_positivos++;
        } else if (num < 0) {
            cout << "Negativo, ";
            qtd_negativos++;
        } else {
            cout << "Zero, ";
            qtd_zeros++;
        }

        bool mult_3 = (num % 3 == 0);
        bool mult_5 = (num % 5 == 0);

        if (mult_3){
            qtd_mult_3++;
        }

        if (mult_5){
            qtd_mult_5++;
        }

        if (mult_3 && mult_5) {
            cout << "Multiplo de 3 e 5";
            qtd_mult_ambos++;
        } else if (mult_3) {
            cout << "Multiplo de 3";
        } else if (mult_5) {
            cout << "Multiplo de 5";
        } else {
            cout << "Nao e multiplo de 3 nem de 5";
        }
        cout << endl << endl;
    }


    double media_pares = (qtd_pares > 0) ? soma_pares / qtd_pares : 0.0;
    double media_impares = (qtd_impares > 0) ? soma_impares / qtd_impares : 0.0;

    system("cls");
    cout << "Pares: " << qtd_pares << " | Impares: " << qtd_impares << endl;
    cout << "Positivos: " << qtd_positivos << " | Negativos: " << qtd_negativos << " | Zeros: " << qtd_zeros << endl;
    cout << "Multiplos de 3: " << qtd_mult_3 << endl;
    cout << "Multiplos de 5: " << qtd_mult_5 << endl;
    cout << "Multiplos de ambos (3 e 5): " << qtd_mult_ambos << endl;
    cout << "--------------------------------------------\n";
    cout << "Maior numero digitado: " << maior << endl;
    cout << "Menor numero digitado: " << menor << endl;
    cout << fixed << setprecision(2);
    cout << "Media dos numeros pares: " << media_pares << endl;
    cout << "Media dos numeros impares: " << media_impares << endl;
    cout << "============================================\n";

    return 0;
}
