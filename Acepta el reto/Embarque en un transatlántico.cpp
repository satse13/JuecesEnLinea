#include <iostream>
using namespace std;

const int Max = 200000;

bool casoDePrueba() {

    int numPasajeros, cubierta[Max], numAcciones, consulta, contAux = 0;
    string accion;


    cin >> numPasajeros;

    if (numPasajeros == 0)
        return false;

    else {

        for (int i = 0; i < numPasajeros; i++) {  
            cin >> cubierta[i];
        }

        cin >> numAcciones;

        for (int i = 0; i < numAcciones; i++) {

            cin >> accion >> consulta;

            if (accion == "EMBARQUE") {

                for (int j = 0; j < numPasajeros; j++) {

                    if (consulta != cubierta[j]) {

                        cubierta[contAux] = cubierta[j];
                        contAux++;
                    }
                }
                numPasajeros = contAux;
                cout << contAux << "\n";
                contAux = 0;
            }
            else if (accion == "CONSULTA") {
                cout << cubierta[consulta - 1] << "\n";
            }
        }
        cout << endl;
        return true;
    }
}

int main() {
    while (casoDePrueba());
    return 0;
}