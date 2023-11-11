//---------------------------------------------------------
// Problema 510 Marketing de zapatos
//
// https://www.aceptaelreto.com
//
// Alejandro Tobias Angeles
//---------------------------------------------------------
#include <iostream>
using namespace std;

bool casoDePrueba() {

	int zapatos[1000], zapPos[1000] = { 0 }, zapNeg[1000] = { 0 };
	int numZap;
	cin >> numZap;
	if (numZap == 0)
		return false;
	else {
		int contadorP = 0, contadorN = 0;
		for (int i = 0; i < numZap; i++) {
			cin >> zapatos[i];
			if (zapatos[i] > 0) {
				zapPos[i] = zapatos[i];
				contadorP++;
			}
			else if (zapatos[i] < 0) {
				zapNeg[i] = zapatos[i];
				contadorN++;
			}
		}

		bool finPos = true;
		bool finNeg = true;
		int i = 0;
		while ((i < numZap - 1) && (finPos || finNeg)) {
			finPos = false;
			finNeg = false;
			for (int j = numZap - 1; j > i; j--) {
				if (zapPos[j] > zapPos[j - 1]) {
					int auxP;
					auxP = zapPos[j];
					zapPos[j] = zapPos[j - 1];
					zapPos[j - 1] = auxP;
					finPos = true;
				}
				if (zapNeg[j] < zapNeg[j - 1]) {
					int auxN;
					auxN = zapNeg[j];
					zapNeg[j] = zapNeg[j - 1];
					zapNeg[j - 1] = auxN;
					finNeg = true;
				}
			}
			if (finPos || finNeg) {
				i++;
			}
		}

		i = contadorP - 1;
		int j = 0;

		while (i >= 0) {
			while (j < numZap) {
				if (zapatos[j] > 0) {
					zapatos[j] = zapPos[i];
					i--;
				}
				j++;
			}
		}

		i = contadorN - 1;
		j = 0;

		while (i >= 0) {
			while (j < numZap) {
				if (zapatos[j] < 0) {
					zapatos[j] = zapNeg[i];
					i--;
				}
				j++;
			}
		}

		for (int i = 0; i < numZap; i++) {
			if (i == numZap - 1) {
				cout << zapatos[i] << "\n";
			}
			else {
				cout << zapatos[i] << " ";
			}
		}

		return true;
	}
}

int main() {
	while (casoDePrueba());
	return 0;
}