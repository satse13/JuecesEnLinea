//---------------------------------------------------------
// Problema 140 Suma de digitos
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

int suma(int numero);
int fractales(int n);


bool casoDePrueba() {

	//leer caso de prueba

	int numero;

	cin >> numero;

		if (numero < 0)
			return false;
		
		else {
			 
			
			int cifra = suma(numero);
			cout << " = " << cifra << '\n';
			

			return true;
		} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int suma(int numero) {

	int resultado;

	if (numero / 10 == 0) {

		cout << numero;
		return numero;
	}
	else {
		 
		int resultado = suma(numero / 10);
		cout << " + " << numero % 10;
		return resultado + (numero % 10);
	}
	
}
	int fractales(int n) {
		if( n == 1)
		return 4;
		else {
			return 4 * n + 4 * fractales(n / 2);
		}
	}
	

	

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main