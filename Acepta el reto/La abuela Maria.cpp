//---------------------------------------------------------
// Problema 337 La abuela Maria
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	const int numDientes = 6;

    int aux, i = 0;

	int dientesSuperiores[numDientes];

	int dientesInferiores[numDientes];

	bool continua = true;

	for (int i = 0; i < numDientes; i++) { //Se escriben los arrays

		cin >> aux;
		dientesSuperiores[i] = aux;

	}

	for (int i = 0; i < numDientes; i++) {
		cin >> aux;
		dientesInferiores[i] = aux;
	}

	while (i < numDientes && continua) { //Se comparan los arrays 

		if((dientesInferiores[i] + dientesSuperiores[i]) != (dientesInferiores[0] + dientesSuperiores[0]))
			continua = false;
		i++;
	}
	if (continua)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

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