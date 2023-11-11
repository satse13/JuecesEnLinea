// Alejandro Tobias Angeles 

// Ejercicio 



#include <iostream>
using namespace std;

bool casoDePrueba() {
	int numCorredores, segundos = 0, tiempoEntrada[100], tiempoOrdenada[100], posicion[100],salida[100];
	string lista;
	cin >> numCorredores;
	if (!cin)
		return false;
	else {
		for (int i = 0; i < numCorredores; i++) {
			cin >> lista;
			segundos = ((lista[0] - 48) * 36000);
			segundos += ((lista[1] - 48) * 3600);
			segundos += ((lista[3] - 48) * 600);
			segundos += ((lista[4] - 48) * 60);
			segundos += ((lista[6] - 48) * 10);
			segundos += ((lista[7] - 48));
			tiempoEntrada[i] = segundos;
			tiempoOrdenada[i] = segundos;
		}

		bool fin = true;
		int i = 0;
		while ((i < numCorredores - 1) && fin) {
			fin = false;
			for (int j = numCorredores - 1; j > i; j--) {
				if (tiempoOrdenada[j] < tiempoOrdenada[j - 1]) {
					int aux;
					aux = tiempoOrdenada[j];
					tiempoOrdenada[j] = tiempoOrdenada[j - 1];
					tiempoOrdenada[j - 1] = aux;
					fin = true;
				}
			}
			if (fin) {
				i++;
			}
		}

		posicion[0] = 1;
		int cont = 1;

		for (int j = 1; j < numCorredores; j++) {
			cont++;
			if (tiempoOrdenada[j] - tiempoOrdenada[j - 1] <= 1) {
				posicion[j] = posicion[j - 1];
			}
			else {
				posicion[j] = cont;
			}
		}

		bool encontrar = false;
		int j;

		for (int i = 0; i < numCorredores; i++) {
			j = 0;
			while (!encontrar && j < numCorredores) {
				if (tiempoOrdenada[j] == tiempoEntrada[i]) {
					salida[i] = posicion[j];
					encontrar = true;
				}
				j++;
			}
			encontrar = false;
		}

		for (int i = 0; i < numCorredores; i++) {
			cout << salida[i] << "\n";
		}
		cout << "---\n";

		return true;
	}
}

int main() {
	while (casoDePrueba());
	return 0;
}
