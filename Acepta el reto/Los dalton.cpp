//---------------------------------------------------------
// Problema 245 Los dalton
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int numDalton;


	cin >> numDalton;

	 
	if (numDalton == 0)
		return false;


	else {
			 
		long long int altura1,altura2,alturaaux;
		bool seguir = true;
		int contador = 0;
		bool desconocidos = false,Amenor = false, Amayor = false;
		
		cin >> altura1;
		cin >> altura2;

		if (altura1 < altura2)
			Amayor = true;
		else if (altura1 > altura2)
			Amenor = true;
		else
			cout << "DESCONOCIDOS" << endl;

		if (Amenor) {

			for (int i = 0; i < numDalton - 2; i++) {

				cin >> alturaaux;

				if (alturaaux >= altura2)
					desconocidos = true;

				altura2 = alturaaux;
			}
		}

		else if (Amayor) {

			for (int i = 0; i < numDalton - 2; i++) {

				cin >> alturaaux;

				if (alturaaux <= altura2)
					desconocidos = true;

				altura2 = alturaaux;
			}

		}

		else{


			for (int i = 0; i < numDalton - 2; i++) {
				cin >> alturaaux;
			}


		}
 
		if (Amenor || Amayor) {

			if (desconocidos)
				cout << "DESCONOCIDOS" << endl;
			else
				cout << "DALTON" << endl;
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