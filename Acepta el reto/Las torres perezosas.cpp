//---------------------------------------------------------
// Problema 181 Las torres perezosas
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int tamanios;
	char tablero[15][15];
	
	cin >> tamanios;


		if (tamanios == 0)
			return false;

		else {
			
			for (int i = 0; i < tamanios; i++) {
				for (int j = 0; j < tamanios; j++) {
					cin >> tablero[i][j];
				}
			}

			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main