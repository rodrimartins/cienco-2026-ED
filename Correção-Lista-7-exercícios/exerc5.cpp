#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    int vetor_original[50];
    int vetor_reorganizado[50];
    int pares = 0, impares = 0;
    int positivos = 0, negativos = 0, zeros = 0;
    int mult_2 = 0, mult_3 = 0, mult_5 = 0;
    int maior, menor;
    int soma = 0;

    do {
        cout << "Digite o tamanho do vetor (entre 10 e 50): ";
        cin >> n;
        if (n < 10 || n > 50) {
            cout << "Erro: O valor deve estar entre 10 e 50.\n";
        }
    } while (n < 10 || n > 50);

    cout << "\n--- Digite os " << n << " numeros ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Posicao [" << i << "]: ";
        cin >> vetor_original[i];
    }

    for (int i = 0; i < n; i++) {
        int num = vetor_original[i];

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

        soma += num;

        if (num % 2 == 0){
           pares++;
        }
        else{
           impares++;
        }

        if (num > 0){
            positivos++;
        }
        else if (num < 0){
            negativos++;
        }
        else{
           zeros++;
        }

        if (num % 2 == 0){
          mult_2++;
        }

        if (num % 3 == 0){
            mult_3++;
        }
        if (num % 5 == 0){
            mult_5++;
        }
    }

    double media = soma / n;

    int index_reorg = 0;

    // Colocar os pares (na ordem original)
    for (int i = 0; i < n; i++) {
        if (vetor_original[i] % 2 == 0) {
            vetor_reorganizado[index_reorg] = vetor_original[i];
            index_reorg++;
        }
    }

    // Colocar os ímpares na ordem inversa
    for (int i = n - 1; i >= 0; i--) {
        if (vetor_original[i] % 2 != 0) {
            vetor_reorganizado[index_reorg] = vetor_original[i];
            index_reorg++;
        }
    }

    bool tem_repetido = false;
    int max_frequencia = 1;
    int num_mais_frequente = vetor_original[0];

    for (int i = 0; i < n; i++) {
        int contagem_atual = 0;

        for (int j = 0; j < n; j++) {
            if (vetor_original[i] == vetor_original[j]) {
                contagem_atual++;
            }
        }

        if (contagem_atual > 1) {
            tem_repetido = true;
        }

        if (contagem_atual > max_frequencia) {
            max_frequencia = contagem_atual;
            num_mais_frequente = vetor_original[i];
        }
    }


    cout << "Vetor Original....: [ ";
    for (int i = 0; i < n; i++){
        cout << vetor_original[i] << " ";
    }
    cout << "]\n";

    cout << "Vetor Reorganizado: [ ";
    for (int i = 0; i < n; i++){
        cout << vetor_reorganizado[i] << " ";
    }
    cout << "]\n";

    cout << "Pares: " << pares << " | Impares: " << impares << "\n";
    cout << "Positivos: " << positivos << " | Negativos: " << negativos << " | Zeros: " << zeros << "\n";
    cout << "Multiplos de 2: " << mult_2 << "\n";
    cout << "Multiplos de 3: " << mult_3 << "\n";
    cout << "Multiplos de 5: " << mult_5 << "\n";
    cout << "Maior valor: " << maior << "\n";
    cout << "Menor valor: " << menor << "\n";
    cout << fixed << setprecision(2);
    cout << "Media geral: " << media << "\n";
    cout << "--------------------------------------------\n";

    if (tem_repetido) {
        cout << "Existem numeros repetidos? SIM\n";
        cout << "Numero que mais se repete: " << num_mais_frequente
             << " (apareceu " << max_frequencia << " vezes)\n";
    } else {
        cout << "Existem numeros repetidos? NAO\n";
        cout << "Nenhum numero se repetiu no vetor.\n";
    }


    return 0;
}
