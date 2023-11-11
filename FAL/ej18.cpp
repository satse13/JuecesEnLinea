# include <iostream>
# include <fstream>
# include <vector>
# include <algorithm>
using namespace std;

using psi = pair <char, int >;

void particion(vector <psi>& v, int& p, int& q) {
	p = 0; q = v.size() - 1; int k = 0;

	while (k <= q) {
		if (v[k].first == 'v') ++k;
		else if (v[k].first == 'a') {
			swap(v[p], v[k]);
			++p; ++k;
		}
		else {
			swap(v[q], v[k]);
			--q;
		}
		
	}
}
bool resuelveCaso() {
	// lectura de los datos de entrada
	int numCintas;
	cin >> numCintas;
	if (!cin)
		return false;
	std::vector <psi> v(numCintas); // nombre y altura
	for (psi& n : v) {
		cin >> n.first >> n.second;
	}
	// resuelve el problema
	int p, q;
	particion(v, p, q);
	// Ordena cada parte para la salida de datos
	sort(v.begin(), v.begin() + p);
	sort(v.begin() + p, v.begin() + 1 + q); // Debe ser 1+q para evitar v. begin () -1 cuando q vale -1
	sort(v.begin() + 1 + q, v.end());
	// Escribe las cintas azules
	cout << "Azules:";
	for (int i = 0; i < p; ++i) {
		 cout << ' ' << v[i].second;
	}
	cout << "\n";
	// Escribe la segunda parte
	cout << "Verdes:";
	for (int i = p; i <= q; ++i) {
		cout << ' ' << v[i].second;
	}
	cout << "\n";
	// Escribe la tercera parte
	cout << "Rojas:";
	for (int i = q + 1; i < v.size(); ++i) {
		cout << ' ' << v[i].second;
	}
	cout << '\n';
	return true;
}
int main() {
	// Para la entrada por fichero .
# ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
# endif
	// Entrada con casos ilimitados
	while (resuelveCaso()); // Resolvemos todos los casos
	// Para restablecer entrada .
# ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}