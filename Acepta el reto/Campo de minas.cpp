//---------------------------------------------------------
// Problema 176 Campo de minas
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

int buscar(const char elementos[1000][1000], int i, int j);


int buscar(const char elementos[1000][1000], int i, int j) {

	 
}


bool casoDePrueba() {

	//leer caso de prueba

	string linea;
	char elementos[1000][1000];
	int filas, columnas;

	cin >> columnas >> filas;;

		if (columnas == 0 && filas == 0)
			return false;
		
		else {
			 
			for (int i = 0; i < filas; i++) {
				for (int j = 0; j < columnas; j++) {
					cin >> elementos[i][j];
				}
			}

			int minas = 0;
			int contador;


			for (int i = 0; i < filas; i++) {
				for (int j = 0; j < columnas; j++) {
					if (elementos[i][j] = '-') {
						cantidad = buscar();

						if (cantidad >= 6)
							minas++;


					}
				}
			}

			cout << minas << endl;

			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main