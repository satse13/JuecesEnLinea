// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// funcioÌn que resuelve el problema
bool sufDisperso(const vector<int>& v, int ini, int fin, int K) {
    if (ini + 1 == fin)
        return true;
    else {
        int m = (ini + fin) / 2;
        bool sIz = sufDisperso(v, ini, m, K);
        bool sDr = sufDisperso(v, m, fin, K);
        return sIz && sDr && K <= std::abs(v[ini] - v[fin - 1]);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (!std::cin) return false;
    int K;
    cin >> K;
    vector <int > v(num);
    for (int& n : v) std::cin >> n;
    if (sufDisperso(v, 0, (int)v.size(), K)) cout << "SI\n";
    else std::cout << "NO\n";
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