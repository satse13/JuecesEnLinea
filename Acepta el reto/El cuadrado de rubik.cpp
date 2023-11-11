//---------------------------------------------------------
// Problema 263 El cuadrado de rubik
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int dimension;

	cin >> dimension;

	//leer caso de prueba
		if (dimension == 0)
			return false;
		else {

			char cubo[50][50];
			char posicion;
			int numero,valor;

			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {

					cin >> cubo[i][j];
					
				}
			}

			cin >> posicion;

			while (posicion != 'x'){
			
				cin >> numero;

				if (posicion == 'f') {

					if (numero > 0) {

						valor = cubo[abs(numero) - 1][dimension-1];

						for (int i = dimension-1; i >= 0; i--) {

							cubo[abs(numero) - 1][i] = cubo[abs(numero) - 1][i - 1];
							
						}
						cubo[abs(numero) - 1][0] = valor;
					}

					else {

						valor = cubo[abs(numero) - 1][0];

						for (int i = 0; i < dimension; i++) {

							cubo[abs(numero) - 1][i] = cubo[abs(numero) - 1][i + 1];

						}

						cubo[abs(numero) - 1][dimension - 1] = valor;

					}


				}

				else {

					if (numero > 0) {

						valor = cubo[dimension - 1][abs(numero) - 1];

						for (int i = dimension - 1; i >= 0; i--) {

							cubo[i][abs(numero) - 1] = cubo[i - 1][abs(numero) - 1];

						}
						cubo[0][abs(numero) - 1] = valor;

					}


					else {
						
						valor = cubo[0][abs(numero) - 1];

						for (int i = 0; i < dimension; i++) {

							cubo[i][abs(numero) - 1] = cubo[i+1][abs(numero) - 1];

						}

						cubo[dimension - 1][abs(numero) - 1] = valor;

					}
				}

				cin >> posicion;
			}

			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {

					cout << cubo[i][j];

				}

				cout << endl;

			}
				
			cout << "---" << endl;
			
			
			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main