
#include <iostream>
using namespace std;

int main() {
	

	int numMontanias;
	int alturas[100000];

	cin >> numMontanias;
	while (numMontanias != 0) {
		for (int i = 0; i < numMontanias; ++i) {
			cin >> alturas[i];
		}



		int cont = 1, siguiente = alturas[numMontanias - 1];


		for (int i = numMontanias - 2; i >= 0; --i) {
			if (alturas[i] > siguiente) {
				cont++;
				siguiente = alturas[i];
			}
		}

		cout << cont << endl;
		cin >> numMontanias;
	}
	
	return 0;
}




