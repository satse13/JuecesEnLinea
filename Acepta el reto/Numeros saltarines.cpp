//---------------------------------------------------------
// Problema 410 Digitos saltarines
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	int previo,dato,contador = 0,i = 0;
	string numero;
	bool hecho[9], fin = false, imposible = false, saltarin = true;

	cin >> numero;

	for (int i = 1; i < 9; i++) {
		hecho[i] = 0;
	}

	hecho[0] = true;
	dato = int(numero[i]) - 48;
	i = (dato + i) % numero.length();
	hecho[i] = true;

	while (!fin && !imposible) {
		if (i != 0) {
			dato = int(numero[i]) - 48;
			previo = i;
			i = (dato + i) % numero.length();

			if (previo == i || dato == 0 || contador == 100) {
				imposible = true;
			}
			else {
				hecho[i] = true;
			}

		}
		else
			fin = true;
		contador++;
	}

	if (imposible)
		saltarin = false;
	i = 0;
	while (saltarin && i < numero.length()) {
		if (!hecho[i])
			saltarin = false;
		else
			i++;
	}

	if (saltarin)
		cout << "SALTARINES" << endl;
	else
		cout << "NORMALES" << endl;
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