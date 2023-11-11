//---------------------------------------------------------
// Problema 237 Numeros polidivisibles
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

bool polidivisible(long long int numero, int longitud);

bool casoDePrueba() {

	//leer caso de prueba

	long long int numero;
	string num;

	cin >> numero;
	num = to_string(numero);

		if (!cin)
			return false;

		else {
			 
			
			bool poli;

			poli = polidivisible(numero, num.length());

			if (poli)
				cout << "POLIDIVISIBLE" << endl;
			else {
				cout << "NO POLIDIVISIBLE" << endl;
			}



			return true;
		} // if-else marca de fin

} // casoDePrueba


bool polidivisible(long long int numero, int longitud) {

	bool resultado;

	if (longitud == 1)
		resultado = true;
	else if (numero % longitud == 0)
		resultado = polidivisible(numero / 10, longitud - 1);
	else
		resultado = false;

	return resultado;
}

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main