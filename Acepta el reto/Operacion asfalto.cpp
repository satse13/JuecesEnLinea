//---------------------------------------------------------
// Problema 212 Operacion asfalto
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int calles;
	

	cin >> calles;



		if (calles == 0)
			return false;
		else {
			 
			int intersecciones;
			int grado[50] = { 0 };
			int vertice;
			int contador = 0;

			cin >> intersecciones;

			for (int i = 0; i < calles; i++) {
				for (int j = 0; j < 2; j++) {
					cin >> vertice;
					grado[vertice]++;
				}
			}

			for (int i = 0; i < intersecciones; i++) {

				if (grado[i] % 2 != 0)
					contador++;

			}

			if (contador < 3)
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