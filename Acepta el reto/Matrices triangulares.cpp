//---------------------------------------------------------
// Problema 160 Matrices triangulares
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int dimension, matriz[50][50];
	bool Tsuperior = true, Tinferior =true;

	cin >> dimension;

	//leer caso de prueba
		if (dimension == 0)
			return false;
		else {
			

			for (int i = 0; i < dimension; i++) {

				for (int j = 0; j < dimension; j++) {

					cin >> matriz[i][j];

					if (i > j) {

						if (matriz[i][j] != 0)
							Tinferior = false;
					}
					else if (j > i) {

						if (matriz[i][j] != 0)
							Tsuperior = false;

					}

				}
			}

			if (Tinferior || Tsuperior)
				cout << "SI" << endl;

			else
				cout << "NO" << endl;




			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main