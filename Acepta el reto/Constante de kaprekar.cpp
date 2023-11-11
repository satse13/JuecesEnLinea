//---------------------------------------------------------
// Problema 100 Constante de Kaprekar
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void casoDePrueba() {

	string numero, inverso, aux;
	int contador = 0,num,menorA, resultado;
	bool repeticion = false;
	const int N = 4;

	cin >> numero;

	numero.append(4 - numero.length(), 48);

	while (!repeticion && numero != "6174") {
		
		bool inter = true;
		int i = 0;
		 
		while ((i < N - 1) && inter) {
			inter = false;
			 
			for (int j = N - 1; j > i; j--) {
				if (numero[j] < numero[j - 1]) {
					int tmp;
					tmp = numero[j];
					numero[j] = numero[j - 1];
					numero[j - 1] = tmp;
					inter = true;
				}
			}
			if (inter) {
				i++;
			}
		}

		aux = numero;
		reverse(aux.begin(), aux.end());
		inverso = aux;

		if (numero == inverso)
			repeticion = true;

		num = (numero[0] - 48) * 1000;
		num = num + ((numero[1] - 48) * 100);
		num = num + ((numero[2] - 48) * 10);
		num = num + ((numero[3] - 48));

		menorA = (inverso[0] - 48) * 1000;
		menorA = menorA + ((inverso[1] - 48) * 100);
		menorA = menorA + ((inverso[2] - 48) * 10);
		menorA = menorA + ((inverso[3] - 48));


		resultado = max(num, menorA) - min(num, menorA);

		 

		numero = to_string(resultado);

		if (resultado < 1000){
			numero = '0' + numero;
		}
		else if (resultado < 100) {
			numero = "00" + numero;
		}
		else if (resultado < 10) {
			numero = "000" + numero;
		}

		contador++;
	}

	if (repeticion)
		cout << 8 << endl;
	else
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