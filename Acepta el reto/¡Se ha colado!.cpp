//---------------------------------------------------------
// Problema 597 Se ha colado
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

void casosDePrueba() {
    int p, n[200000], minimo, contador = 0;
    cin >> p;

    for (int i = 0; i < p; i++) {
        cin >> n[i];
    }

    minimo = n[p - 1];

    for (int i = p - 1; i > 0; i--) {
        if (n[i - 1] < minimo) {
            minimo = n[i - 1];
        }
        else {
            contador++;
        }
    }

    cout << contador << "\n";
}

//--------------------------------------------------------------------------

int main()
{
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        casosDePrueba();
    }
    return 0;
}