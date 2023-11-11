//---------------------------------------------------------
// Problema <num> <Titulo>
//
// https://www.aceptaelreto.com
//
// <Tu nombre aqu�>
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

bool casoDePrueba() {

	//leer caso de prueba
	
	int numSillas;
	cin >> numSillas;
	
	if (numSillas == 0)
			return false;
	else {
		
		string comensales;	
		cin >> comensales;
		int contador = 0;
		bool de = false, iz= false;
		for (int i = 0; i < comensales.length(); i++) {
			if  (comensales[i] == 'D') {
				de = true;
			}

			else if (comensales[i] == 'I') {
				iz = true;
			}
		}
			
		if (de && iz)

			cout << "ALGUNO NO COME" << endl;

		else
			cout << "TODOS COMEN" << endl;

		return true;
	} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main