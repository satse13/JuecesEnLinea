//---------------------------------------------------------
// Problema 598 Comienza la temporada
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	//leer caso de prueba

	int jugadores,equipaciones;

	cin >> jugadores;
	cin >> equipaciones;


		if (!cin)
			return false;
		else {

			int tallas[100000];
			int tequipaciones[100000];
			bool encontrado = false;


			for (int i = 0; i < jugadores; i++) {

				cin >> tallas[i];
			}

			for (int i = 0; i < equipaciones; i++) {

				cin >> tequipaciones[i];

			}

			int contador = jugadores;

			for (int i = 0; i < jugadores; i++) {

				int j = 0;

				while (j < equipaciones && !encontrado) {

					if (tequipaciones[j] == tallas[i] || tequipaciones[j] == tallas[i] + 1) {

						contador--;
						encontrado = true;
						tequipaciones[j] = 0;
						

					}

					j++;
				}

				encontrado = false;
			}
			

			 

			cout << contador << endl;


			

			// C�DIGO PRINCIPAL AQU�
			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main