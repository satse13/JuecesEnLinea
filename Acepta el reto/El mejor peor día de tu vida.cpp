//---------------------------------------------------------
// Problema 468 El mejor peor dia de tu vida
// 
// // https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <vector>
#include <iostream>
using namespace std;

bool casoDePrueba() {

	int numElementos;

	cin >> numElementos;

		if (!cin)
			return false;
		else {

			  int maximo = 0;
			  int elemento;
			
			  vector <int> array;

			for (int i = 0; i < numElementos; i++) {

				cin >> elemento;
					array.push_back(elemento);
				if (array[i] > maximo)
					maximo = array[i];
			}

			int resultado = maximo - array[0];

			cout << resultado << endl;



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