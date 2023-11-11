//---------------------------------------------------------
// Problema 194 Salvemos al lince ibérico
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {

	string vallas;
	int contador = 0;
	cin >> vallas;

	for (int i = 0; i < vallas.length(); i++) {		// Como para cubrir 3 caractereres solo hace falta un tunel simplemente hay que mirar que haya un punto de cada 3
		
		if (vallas[i] == '.') {
			contador++;
			i = i + 2; // Se pone i + 2 y no i + 3 pq el for ya se encarga de hacer i++ al final del bucle 
		}

	}

	
	cout << contador << endl;


} // casoDePrueba

//---------------------------------------------------------

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;

	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;

} // main