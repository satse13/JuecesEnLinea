//---------------------------------------------------------
// Problema 272 Tres dedos en cada mano
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

void conversion(int numero);

void casoDePrueba() {

	int numero;

	cin >> numero;
	

	if (numero == 0)
		cout << 0 << endl;
	else {
		conversion(numero);

		cout << endl;
	}
	 

} // casoDePrueba

//--------------------------------------------------------

void conversion(int numero) {

	int aux;

	if (numero != 0) {
		aux = numero % 6;

		numero = numero / 6;

		conversion(numero);

		cout << aux;
	}
}

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;

	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;

} // main