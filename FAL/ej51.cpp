#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;
using lli = long long int;

struct tSol {
	lli resultado;
	bool valido;
};

tSol resolver(lli n) {
	if (n < 10) {
		if (n == 1) {
			return { 1,true };
		}
		else {
			if (n == 0)
				n = 1;
			return { n,false };
		}
	}
	else {
		tSol sol = resolver(n / 10);
		bool uno = n % 10 == 1;
		if (!sol.valido) {
			if (n % 10 == 0)
				return{ sol.resultado * 9 - (9 - 1 % 10),uno };
			
			return { sol.resultado * 9 - (9 - n % 10), uno };
		}
		else {
			return { sol.resultado * 9, sol.valido };
		}

	}
	
}

lli funct(lli n) {
	tSol result = resolver(n);
	return result.resultado;
}
 
bool resuelveCaso() {
	// leer los datos de la entrada

	lli n = 0;
	cin >> n;

	if (!std::cin)
		return false;

	lli sol = funct(n);
	cout << sol << endl;

	// escribir sol

	return true;
	

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}