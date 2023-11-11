//---------------------------------------------------------
// Problema 399 Las perlas de la condesa
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {
	int perlas[1000],salida[1000];
	int contador = 1;
	bool resultado = false;
	bool fin = false;

	cin >> perlas[0];
	
	if (perlas[0] == 0)
		return false;

	else {

		while (!fin) {
			cin >> perlas[contador];

			if (perlas[contador] == 0)
				fin = true;
			else
			contador++;
		}
			
		if (contador % 2 == 1) {
			bool inter = true;
			int i = 0;
 			while ((i < contador - 1) && inter) {
				inter = false;
 				for (int j = contador - 1; j > i; j--) {
					if (perlas[j] < perlas[j - 1]) {
						int tmp;
						tmp = perlas[j];
						perlas[j] = perlas[j - 1];
						perlas[j - 1] = tmp;
						inter = true;
					}
				}
				if (inter) {
					i++;
				}
				resultado = true;
			}

			for (int i = 0, j = 0, k = contador - 1; i < contador; i = i + 2) {
				if (perlas[i] == perlas[i + 1] && i < contador - 1) {
					salida[j] = perlas[i];
					j++;
					salida[k] = perlas[i];
					k--;
				}
				else if (i == contador - 1) {
					salida[j] = perlas[i];
				}
				else
					resultado = false;
			}

			if (contador == 1)
				resultado = true;

			if (!resultado)
				cout << "NO" << endl;

			else {

				for (int i = 0; i < contador; i++) {
					if (i == 0)
						cout << salida[i];
					else
						cout << " " << salida[i];
				}
				cout << endl;
			}
		}

		else {
			cout << "NO" << endl;
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