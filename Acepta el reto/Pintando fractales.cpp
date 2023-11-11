//---------------------------------------------------------
// Problema 167 Alejandro Tobias
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

int fractales(int longitud);


bool casoDePrueba() {

	int longitud;	

	cin >> longitud;
	 
		if (!cin)
			return false;
		else {
			 
			int resultado = fractales(longitud);

			cout << resultado << endl;

			return true;
		} // if-else marca de fin

} // casoDePrueba

int fractales(int n) {
	if (n == 1)
		return 4;
	else {
		return 4 * n + 4 * fractales(n / 2);
	}
}


//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main