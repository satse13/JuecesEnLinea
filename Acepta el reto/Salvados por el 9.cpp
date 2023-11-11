//---------------------------------------------------------
// Problema 572 Salvados por el 9
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

const int actividades = 5;

void casoDePrueba() {

	
	double nota;
	bool cero = false, nueve = false;;

	for (int i = 0; i < actividades; i++) {

		cin >> nota;

		if (nota == 0.0)
			cero = true;
		else if (nota >= 9)
			nueve = true;
	}
	if (cero && !nueve)
		cout << "SUSPENSO DIRECTO" << endl;
	else
		cout << "MEDIA" << endl;



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