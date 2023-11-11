//---------------------------------------------------------
// Problema 266 Copistas daltonicos
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

const int N = 500;

bool casoDePrueba() {
    int filas, columnas, copistas;
    char cuadro[N][N], color, colorSus;
    char letra[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    cin >> filas >> columnas;

    if (filas == 0 && columnas == 0)
        return false;
    else {

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> cuadro[i][j];
            }
        }

        cin >> copistas;
        int p = 0;

        for (int i = 0; i < copistas; i++) {
            cin >> color >> colorSus;
            while (p < 26) {
                if (letra[p] == color) {
                    letra[p] = colorSus;
                }
                p++;
            }
            p = 0;
        }

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << letra[int(cuadro[i][j] - 65)];
            }
            cout << "\n";
        }

        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}
