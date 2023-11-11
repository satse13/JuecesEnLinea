//---------------------------------------------------------
// Problema 168 - La pieza perdida
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	const int tamanio = 10000;

	int numero = 0;

	int marca;

	long double numPiezas;

	bool hay[tamanio];

	cin >> numPiezas;
   //leer caso de prueba
		if (numPiezas == 0)
			return false;
		else {
			
			for (int i = 0; i < numPiezas; i++) {
				hay[i] = false;
			}
			for (int i = 1; i <= numPiezas - 1; i++) {
				cin >> marca;
				hay[marca - 1] = true;
			}

			while ((numero < numPiezas) && (hay[numero])) {
				numero++;
			}

			cout << numero + 1 << endl;
			 
			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main