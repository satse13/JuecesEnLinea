//---------------------------------------------------------
// Problema 543 Tension en la playa
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
#include <math.h>
using namespace std;

void casosDePrueba() {
    int n, x[100], y[100], r[100], sumaR;
    double d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    int nivelDeTension = 0;
    int i = 0;
    while (i < n) {
        for (int j = i + 1; j < n; j++) {
            sumaR = r[i] + r[j];
            d = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
            if (d < sumaR) {
                nivelDeTension++;
            }
        }
        i++;
    }
    cout << nivelDeTension << "\n";
}

//--------------------------------------------------------------------------

int main()
{
    unsigned int numCasos, i;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        casosDePrueba();
    }
    return 0;
}