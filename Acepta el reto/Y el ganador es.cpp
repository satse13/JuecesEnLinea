#include <iostream>
#include <string>
using namespace std;

bool casoDePrueba() {
    int nEquipos, nGlobos, equipo, puntos[20], max = 0, contMax = 0, equipoMax;
    string color;

    cin >> nEquipos >> nGlobos;

    if (nEquipos == 0 && nGlobos == 0)
        return false;
    else {
        for (int i = 0; i < 20; i++) {
            puntos[i] = 0;
        }
        for (int i = 0; i < nGlobos; i++) {
            cin >> equipo >> color;
            puntos[equipo - 1]++;
        }
        for (int i = 0; i < 20; i++) {
            if (puntos[i] > max) {
                max = puntos[i];
                equipoMax = i + 1;
            }
        }
        for (int i = 0; i < 20; i++) {
            if (puntos[i] == max) {
                contMax++;
            }
        }
        if (nEquipos == 1) {
            cout << "1\n";
        }
        else if (contMax <= 1) {
            cout << equipoMax << "\n";
        }
        else if (contMax > 1) {
            cout << "EMPATE\n";
        }

        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}