#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    double L, S1, S2;

    cout << "Digite o primeiro lado: ";
    cin >> a;
    cout << "Digite o segundo lado: ";
    cin >> b;
    cout << "Digite o terceiro lado: ";
    cin >> c;

    if (a < (b + c) && b < (a + c) && c < (a + b)) {
        cout << "Resultado: Os valores informados FORMAM um triangulo.\n";

        cout << "Classificacao por lados: ";
        if (a == b && b == c) {
            cout << "Triangulo Equilatero" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "Triangulo Isosceles" << endl;
        } else {
            cout << "Triangulo Escaleno" << endl;
        }


        if (a >= b && a >= c) {
            L = a; S1 = b; S2 = c;
        } else if (b >= a && b >= c) {
            L = b; S1 = a; S2 = c;
        } else {
            L = c; S1 = a; S2 = b;
        }

        double L2 = L * L;
        double soma_S2 = (S1 * S1) + (S2 * S2);

        cout << "Classificacao por angulos: ";

        if (L2 == soma_S2) {
            cout << "Triangulo Retangulo" << endl;
        } else if (L2 > soma_S2) {
            cout << "Triangulo Obtusangulo" << endl;
        } else {
            cout << "Triangulo Acutangulo" << endl;
        }

    } else {

        cout << "Resultado: Nao forma um triangulo." << endl;
    }

    return 0;
}
