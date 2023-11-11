#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

bool resuelveCaso() {
    int n, m;

    cin >> n;

    if (!std::cin)
        return false;
    cin >> m;

    vector<int> v(n);
    unordered_map<int, vector<int>> mapa;
    int aux;

    for (int i = 0; i < n; ++i) {
        cin >> aux;
        mapa[aux].push_back(i + 1);
    }

    int veces, num;
    for (int i = 0; i < m; ++i) {
        cin >> veces >> num;

        if (!mapa.count(num) || mapa[num].size() < veces)
            cout << 0;
        else
            cout << mapa[num][veces - 1];
        cout << '\n';
    }

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