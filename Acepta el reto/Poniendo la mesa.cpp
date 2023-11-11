//---------------------------------------------------------
// Problema 515 Poniendo la mesa
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

int paseos(int copas);

bool casoDePrueba() {

	//leer caso de prueba
		
	int numero;

	cin >> numero;
	bool fin = false;

	if (numero == 0)
			return false;

	else {
		 
		if (numero == 1)
			cout << numero << endl;
		else if (numero % 2 == 1)
			cout << numero - 1 << endl;
		else
			cout << numero << endl;


		return true;
	} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main