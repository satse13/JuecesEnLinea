//---------------------------------------------------------
// Problema 154 ¿Cual es la siguiente matricula?
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int posicionLetra(char letra);
const char letras[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};

bool casoDePrueba() {

	long long int numMatricula;
	string letrasMatricula;
	
	cin >> numMatricula; cin >> letrasMatricula;

		if (numMatricula == 9999 && letrasMatricula == "ZZZ")
			return false;
		else {
			
			numMatricula = (numMatricula + 1) % 10000;

			if (numMatricula == 0000) {

				int i;

				i = posicionLetra(letrasMatricula[2]);
				if(i != 20)
					letrasMatricula[2] = letras[i + 1];
				else {
					letrasMatricula[2] = 'B';
					i = posicionLetra(letrasMatricula[1]);
					if (i != 20)
						letrasMatricula[1] = letras[i + 1];
					else {
						letrasMatricula[1] = 'B';
						i = posicionLetra(letrasMatricula[0]);
						letrasMatricula[0] = letras[i + 1];
						
					}

				}

			}

			cout.width(4);
			cout.fill('0');
			cout << numMatricula << " " << letrasMatricula << endl;

			return true;

		} // if-else marca de fin		
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main

int posicionLetra(char letra) {

	int posicion = 0;
	int i = 0;
	bool encontrado = false;
	


	while (i < 21 && !encontrado) {

		if (letra == letras[i]) {
			posicion = i;
			encontrado = true;
		}
		i++;
		
	}
	return posicion;
}