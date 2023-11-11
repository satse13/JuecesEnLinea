//---------------------------------------------------------
// Problema 136 Encadenando Trolls
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------

#include <iostream>

using namespace std;

bool resuelve();
int numCortes(int numEslabones, int fuerza);

 
int main() {
 

	while (resuelve());

	return 0;

} // main

 bool resuelve() {
	int numEslabones, fuerza;
	cin >> fuerza >> numEslabones;
	fuerza *= 2;

	if (fuerza == 0)
		return false;

	cout << numCortes(numEslabones, fuerza) << "\n";
	return true;
}

int numCortes(int numEslabones, int fuerza) {
	if (numEslabones <= fuerza)
		return 0;
	int ladoCorto = numEslabones / 3;
	int ladoLargo = numEslabones - ladoCorto;

	int a = numCortes(ladoCorto, fuerza);
	int b = numCortes(ladoLargo, fuerza);
	return a + b + 1;
}
 