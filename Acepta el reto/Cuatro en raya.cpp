#include "Cuatro en raya.h"


int main() {

	int primerColor;
	tTablero tablero;
	bool fin = false,cambioTurno = false;
	tCasilla jugadorTurno;

	InicializarTablero(tablero);

	cout << "Elige con que color quieres jugar (1 - rojo || 2 - blanco): ";
	cin >> primerColor;

	while (primerColor != 1 && primerColor != 2) {
		cout << "Ese no es un color valido, por favor vuelve a introducir con que color quieres jugar" << endl;
		cout << "Elige con que color quieres jugar (1 - rojo || 2 - blanco): ";
		cin >> primerColor;
	}

	if (primerColor == 1)
		jugadorTurno = rojo;
	else
		jugadorTurno = blanco;

	cout << "Muy bien, has elegido el color " << Tostring(jugadorTurno) << endl;

	cout << "Al otro jugador se le asigna el color ";

	if (primerColor == 1)
		cout << blanco;
	else
		cout << rojo;
	
	while (!fin) {

		visualizarTablero(tablero);
		system("pause");




	}

	cout << "Enhorabuena jugador " << Tostring(jugadorTurno) << "has ganado!" << endl;
	
	return 0;
} 

void InicializarTablero(tTablero tablero) {

	for (int i = 0; i < FILA; i++ ) {
		for (int j = 0; j < COLUMNA; j++) {

			tablero[i][j] = libre;
		}
	}
}

void escribeCasilla(tCasilla casilla) {

	switch (casilla) {
	case blanco:
		colorFrente(15);
		cout << "O";
		break;
	case rojo:
		colorFrente(4);
		cout << "O";
		break;
	case libre:
		colorFrente(0);
		cout << " ";
		break;
	}
}

void visualizarTablero(tTablero tablero) {
	cout << "________";
	cout << endl;

	for (int i = FILA - 1; i >= 0; i--) {
		cout << i + 1 << " ";
		for (int j = 0; j < COLUMNA; j++) {
			colorFrente(15);
			cout << " |";
			escribeCasilla(tablero[i][j]);
			colorFrente(15);
		}

		cout << endl;
		cout << "  _________";
		cout << endl;

	}
	cout << " ";
	for (int i = 1; i < COLUMNA; i++) {
		cout << " " << i << " ";
	}
	cout << endl;
}

bool comprobarGanador(tTablero tablero, tCasilla jugador, int columna) {

	bool resultado = false;


	for (int i = 0; i < FILA; i++) {
		for(int j = 0; j < COLUMNA;j++){
		
		
		
		}

	}





	return resultado;
}


void colorFrente(int color) {

	if(color == rojo)
		

}




