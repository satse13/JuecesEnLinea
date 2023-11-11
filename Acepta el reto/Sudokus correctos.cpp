//---------------------------------------------------------
// Problema 345 Sudokus correctos
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>
using namespace std;

const int MAX = 9;

void casoDePrueba() {

	
	int sudoku[9][9],k;
	bool fila[9] = { 0 },fin,contador = 0;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {

			cin >> sudoku[i][j];
		}
	}
	 


	for (int i = 0; i < 9; i++) { // Comprueba filas
		
		for (int j = 0; j < 9; j++) {

			if (!fila[sudoku[i][j] - 1])
				fila[sudoku[i][j] - 1] = true;
			else
				fin = true;

		}
	}

	bool columna[9] = { 0 }; //Comprueba columnas

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {

			if (!columna[sudoku[j][i] - 1])
				columna[sudoku[j][i] - 1] = true;
			else
				fin = true;

		}
	}

	 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9;j++) {

			contador += sudoku[i][j];
		}
		if (contador != 45)
			fin = true;

		contador = 0;
	}

	if (fin)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;


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