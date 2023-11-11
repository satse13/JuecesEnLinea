//---------------------------------------------------------
// Problema 553 Traduciendo apuntes
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

struct tProfesor {
    int pagIni;
    int pagFin;
};

struct tProfesores {
    tProfesor profe[2000];
    int cont = 0;
};

bool casoDePrueba() {
    tProfesores profesores;
    cin >> profesores.cont;
    if (profesores.cont == 0)
        return false;
    else {
        for (int i = 0; i < profesores.cont; i++) {
            cin >> profesores.profe[i].pagIni >> profesores.profe[i].pagFin;
        }

        bool fin = true;
        int i = 0;
        while ((i < profesores.cont - 1) && fin) {
            fin = false;
            for (int j = profesores.cont - 1; j > i; j--) {
                if (profesores.profe[j].pagIni < profesores.profe[j - 1].pagIni) {
                    tProfesor aux;
                    aux = profesores.profe[j];
                    profesores.profe[j] = profesores.profe[j - 1];
                    profesores.profe[j - 1] = aux;
                    fin = true;
                }
            }
            if (fin) {
                i++;
            }
        }
        int aux1, aux2;
        for (int i = 0; i < profesores.cont; i++) {
            if (i != profesores.cont - 1) {
                if (profesores.profe[i].pagFin >= profesores.profe[i + 1].pagFin) {
                    aux1 = profesores.profe[i].pagFin;
                    profesores.profe[i].pagFin = profesores.profe[i + 1].pagFin;
                    profesores.profe[i + 1].pagFin = aux1;

                    aux2 = (profesores.profe[i].pagFin + 1);
                    profesores.profe[i + 1].pagIni = aux2;
                }
                else if (profesores.profe[i].pagFin >= profesores.profe[i + 1].pagIni) {
                    profesores.profe[i + 1].pagIni = profesores.profe[i].pagFin + 1;
                }
            }
        }

        int total = 0;

        for (int i = 0; i < profesores.cont; i++) {
            total += ((profesores.profe[i].pagFin - profesores.profe[i].pagIni) + 1);
        }

        cout << total << endl;
        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}