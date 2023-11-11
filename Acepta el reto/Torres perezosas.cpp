//---------------------------------------------------------
// Problema 266 <Titulo>
//
// https://www.aceptaelreto.com
//
// <Tu nombre aqu�>
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
			 
			char tablero[15][15];

			int num[15][15];



			for (int i = 0; i < dimension; i++) {
				for(int j = 0; j < dimension; j++){
					cin >> tablero[i][j];
					
					if (tablero[i][j] == '.')
						num[i][j] = 1;
					else
						num[i][j] = 0;
				}
			}


			bool bloqueo = false;

			for (int i = 0; i < dimension; i++) {
				if (num[dimension - 1][i] == 0)
					bloqueo = true;
				if (bloqueo)
					num[dimension - 1][i] = 0;
			}
			bloqueo = false;

			for (int i = dimension - 1; i >= 0; i--) {
				if (num[i][0] == 0)
					bloqueo = true;
				if (bloqueo)
					num[i][0] = 0;
			}

			for (int i = dimension - 2; i >= 0; i--) {
				for (int j = 1; j < dimension; j++) {

					if (num[i][j] != 0) {
						num[i][j] = num[i + 1][j] + num[i][j-1];
					}
				}
			}

			cout << num[0][dimension - 1] << endl;

			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main