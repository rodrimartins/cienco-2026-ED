#include <iostream>
using namespace std;

void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        // Troca
        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
}

int main() {
    int vetor[10];

    cout << "Digite 10 numeros:\n";
    for (int i = 0; i < 10; i++) {
        cin >> vetor[i];
    }

    selectionSort(vetor, 10);

    cout << "\nVetor ordenado:\n";
    for (int i = 0; i < 10; i++) {
        cout << vetor[i] << " ";
    }

    int menorValor = vetor[0];
    int maiorValor = vetor[9];

    int contMenor = 0, contMaior = 0;

    for (int i = 0; i < 10; i++) {
        if (vetor[i] == menorValor) {
                contMenor++;
        }
        if (vetor[i] == maiorValor) {
                contMaior++;
        }
    }

    cout << "\n\nMenor numero: " << menorValor;
    cout << "\nQuantidade de vezes que aparece: " << contMenor;

    cout << "\n\nMaior numero: " << maiorValor;
    cout << "\nQuantidade de vezes que aparece: " << contMaior;

    return 0;
}
