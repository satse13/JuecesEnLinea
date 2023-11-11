#include <iostream>
using namespace std;

const short N = 9;
void casosDePrueba() {

    short sudoku[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];
        }
    }

    bool salir = false;

    for (int i = 0; !salir && i < N; i++) {
        for (int j = 0; !salir && j < N; j++) {
            for (int k = j + 1; !salir && k < N; k++) {
                if (sudoku[i][j] == sudoku[i][k]) {
                    salir = true;
                }
            }
        }
    }

    for (int i = 0; !salir && i < N; i++) {
        for (int j = 0; !salir && j < N; j++) {
            for (int k = j + 1; !salir && k < N; k++) {
                if (sudoku[j][i] == sudoku[k][i]) {
                    salir = true;
                }
            }
        }
    }

    int total = 0;
    int auxK = 0;
    int auxI = 0;
    int auxJ = 0;
    int cont = 0;
    int contI = 0;

    for (int i = auxI; !salir && i <= N; i = i + 3) {
        i = auxI;
        for (int j = auxJ, k = auxK; !salir && k != auxK + 3; j++) {
            total = total + sudoku[k][j];
            if (j == 2) {
                k++;
                j = -1;
            }
            else if (j == 5) {
                k++;
                j = 2;
            }
            else if (j == 8) {
                k++;
                j = 5;
            }
        }
        cont++;
        contI++;
        if (total != 45) {
            salir = true;
        }
        if (cont == 3) {
            total = 0;
            auxI = contI;
            auxJ = auxJ + 3;
            cont = 0;
            auxK = 0;
            if (contI == 9) {
                i = 10;
            }
        }
        else {
            total = 0;
            auxK = auxK + 3;
        }
    }


    if (salir) {
        cout << "NO\n";
    }
    else {
        cout << "SI\n";
    }
}

int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        casosDePrueba();
    }
    return 0;
}