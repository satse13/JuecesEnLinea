// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
int resolver(vector<int>& v, int ini, int fin) {
    if (ini + 1 == fin) return 0; //un elemento;
    else if (ini + 2 == fin) {
        if (v[ini] > v[ini + 1]) {
             return 1;
        }
        return 0;
    }
    else {
        int mitad = (ini + fin) / 2;
        int iz = resolver(v, ini, mitad);
        int dc = resolver(v, mitad, fin);
        inplace_merge(v.begin() + ini, v.begin() + (ini + mitad) / 2, v.begin() + mitad);
        inplace_merge(v.begin() + mitad, v.begin() + (mitad + fin) / 2, v.begin() + fin);
        int sol = iz + dc;
        int i = ini, j = mitad;
        while (i < mitad && j < fin) {
            if (v[i] <= v[j]) {
                i++;
            }
            else {
                sol += mitad - i;
                j++;
            }
        }
        return sol;
    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nNaves; cin >> nNaves;
    if (!std::cin)
        return false;

    vector<int> v(nNaves);
    for (int& x : v) cin >> x;

    int sol = resolver(v, 0, v.size());

    // escribir sol
    cout << sol << endl;
    /* for (int& x : v) cout << x;
     cout << endl;*/

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