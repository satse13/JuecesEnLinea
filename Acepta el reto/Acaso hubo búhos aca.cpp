//---------------------------------------------------------
// Problema 252 Acaso hubo buhos aca
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Alejandro
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

bool casoDePrueba() {

	string oracion;
	long long int alante = 0, aux = 0, i = 0, atras = 0;
	bool continuar = true, comparar;

	getline(cin, oracion);

		if (oracion == "XXX")
			return false;

		else {

			for (int i = 0; i < oracion.length(); i++) {
				if (oracion[i] != ' ') {
					aux++;
					if (oracion[i] != tolower(oracion[i]))
						oracion[i] = tolower(oracion[i]);
				}
			}
			
			while (continuar && i < aux / 2) {
				comparar = true;

				if (oracion[oracion.length() - 1 - i - atras] == ' ') {
					atras++;
					comparar = false;
				}

				if (oracion[i + alante] == ' ') {
					alante++;
					comparar = false;
				}

				if (comparar)
				{
					if (oracion[i + alante] != oracion[oracion.length() - 1 - i - atras]) {
						continuar = false;
					}
					i++;
				}
			}
			if (continuar)
				cout << "SI" << endl;
			else
				cout << "NO" << endl;

		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} 
// main

