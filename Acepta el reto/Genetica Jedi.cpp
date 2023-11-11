//---------------------------------------------------------
// Problema 431 Genetica Jedi
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias
//---------------------------------------------------------

#include <iostream>

using namespace std;

bool casoDePrueba() {

	int numFamilias,numHijos, midiclorianos;
	int fuerza;
	int mejor = 0;
	int mejores[20];

	cin >> numFamilias;

	//leer caso de prueba
		if  (numFamilias == 0)
			return false;

		else {

			for (int i = 0; i < numFamilias; i++) {

				cin >> numHijos >> midiclorianos;

				for (int j = 0; j < numHijos; j++) {
					cin >> fuerza;
					if ((fuerza * midiclorianos) > mejor) {
						mejor = fuerza * midiclorianos;
					}
				}
				mejores[i] = mejor;
				mejor = 0;
			}			 
			
			int tmp;
 			for (int i = 0; i < numFamilias - 1; i++) {
 				for (int j = numFamilias - 1; j > i; j--) {
					if (mejores[j] > mejores[j - 1]) {
						tmp = mejores[j];
						mejores[j] = mejores[j - 1];
						mejores[j - 1] = tmp;
					}
				}
			}

			for (int i = 0; i < numFamilias; i++) {
				if (i == numFamilias - 1) {
					cout << mejores[i] << "\n";
				}
				else {
					cout << mejores[i] << " ";
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