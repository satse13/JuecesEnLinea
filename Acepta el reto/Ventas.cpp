//---------------------------------------------------------
// Problema <num> <Titulo>
//
// https://www.aceptaelreto.com
//
// <Tu nombre aqu�>
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	//leer caso de prueba

	const int  DIAS_SEMANA = 6;
	int ventas[DIAS_SEMANA];
	string dia_mayor, dia_menor,resultado;

	for (int i = 0; i < DIAS_SEMANA; i++) {
		cin >> ventas[i];
	}

		if (ventas[6] == -1)
			return false;

		else {
		
			int mayor = ventas[0],menor = ventas[0], suma = 0;

			for (int i = 1; i < DIAS_SEMANA; i++) {

				if (ventas[i] > mayor)
					mayor = i;


				else if (ventas[i] < menor)
					menor = i;

				else if(ventas[i] == mayor)

				suma = suma + ventas[i];

			}

			suma = suma / DIAS_SEMANA; 

			switch (mayor)
			{
			case 0: dia_mayor = "MARTES"; break;
			case 1: dia_mayor = "MIERCOLES";break;
			case 2: dia_mayor = "JUEVES"; break;
			case 3: dia_mayor = "VIERNES"; break;
			case 4: dia_mayor = "SABADO"; break;

			default:
				break;
			}
			switch (menor)
			{
			case 0: dia_menor = "MARTES"; break;
			case 1: dia_menor = "MIERCOLES"; break;
			case 2: dia_menor = "JUEVES"; break;
			case 3: dia_menor = "VIERNES"; break;
			case 4: dia_menor = "SABADO"; break;

			default:
				break;
			}

			if (ventas[DIAS_SEMANA] > suma)
				resultado = "SI";
			else
				resultado = "NO";

			cout << dia_mayor << " " << dia_menor << " " << resultado;

			return true;
		} 

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main