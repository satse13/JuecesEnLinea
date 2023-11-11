//---------------------------------------------------------
// Problema 367 Repartiendo regalos en tu calle
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles 
//---------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

void casoDePrueba() {

	int aterrizaje, numPortales, portales[1000];
	int salida[1000];
	int posicion, diferencia = 1000;
	int cercano;
	bool pasado[1000] = { 0 };

	cin >> aterrizaje >> numPortales;
	cercano = aterrizaje;
	posicion = aterrizaje;

	for (int i = 0; i < numPortales; i++) {
		cin >> portales[i];
	}

	bool inter = true;
	int i = 0;
	while ((i < numPortales - 1) && inter) {
		inter = false;
		for (int j = numPortales - 1; j > i; j--) {
			if (portales[j] < portales[j - 1]) {
				int tmp;
				tmp = portales[j];
				portales[j] = portales[j - 1];
				portales[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter) {
			i++;
		}
	}

	for (int j = 0; j < numPortales; j++) {

		for (int i = 0; i < numPortales; i++) {

			if (abs(portales[i] - cercano) <= diferencia && !pasado[i]) {
				diferencia = abs(portales[i] - cercano);
				posicion = i;
			}
		}
		cercano = portales[posicion];
		pasado[posicion] = true;
		salida[j] = cercano;
		diferencia = 1000;
	}

	for(int i = 0; i< numPortales;i++){
		if (i == numPortales - 1)
			cout << salida[i] << endl;
		else
			cout << salida[i] << " ";
	}
		 
} // casoDePrueba

//---------------------------------------------------------

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;

	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;

} // main