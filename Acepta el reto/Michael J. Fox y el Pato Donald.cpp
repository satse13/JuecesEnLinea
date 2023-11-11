//---------------------------------------------------------
// Problema 416 Michael J. Fox y el Pato Donald
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int casos;

	cin >> casos;

	
	//leer caso de prueba
		if (casos == 0)
			return false;

		else {
			 
			int dia, mes, anio;
			string barrita;
			int i = 0;
			bool  fechas[32][13] = { 0 }; // Asi se inicializa el array entero en false
										  // Fechas y dias tienen es un numero mas de lo normal igual que en el del ciclo hamiltoniano

			bool repetido = false;

		 
			// Hay que hacerlo con un for porque sigues teniendo que leer toda la entrada


			while(i < casos && !repetido) {  

				cin >> dia; // como hay que coger numeros enteros separas la fecha en cada uno de estos parametros
				cin >> barrita;
				cin >> mes;
				cin >> barrita;
				cin >> anio;

				if (fechas[dia][mes] == true)  // Si la fecha que nos meten ya estaba puesta repetidos = true
					repetido = true;

				else // Si no lo estaba hagamos que figure en el array 
				fechas[dia][mes] = true;


				// De esta forma podemos identificar si la nueva fecha ya habia sido introducida en algun momento 
				// El array de booleanos tambien se uso en el problema del ciclo hamiltoniano 


				i++;

			}
			 

			if (repetido)
				cout << "SI" << endl;
			else
				cout << "NO" << endl;


			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main