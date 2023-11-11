// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funcioÌn que resuelve el problema
struct tSol {
    bool alguno; // Este parametro mide si el jugador juega o no
    int nPartidos = 0, ronda = 0;
};
// función que resuelve el problema

// EL parametro r es la ronada hasta la que podemos llegar
tSol resolver(const vector<string>& v, int ini, int fin, int r) {
    if (ini + 1 == fin) {
        tSol sol;
        sol.alguno = v[ini] != "NP";
        sol.ronda = 0;
        sol.nPartidos = 0;
        return sol;
    }
    
    else {
        int mitad = (ini + fin) / 2;
        tSol iz = resolver(v, ini, mitad, r);
        tSol dc = resolver(v, mitad, fin, r);

        tSol sol;

        sol.nPartidos = dc.nPartidos + iz.nPartidos;
        sol.ronda = iz.ronda;
        if (sol.ronda < r) {
            sol.alguno = iz.alguno || dc.alguno;
            sol.nPartidos += (iz.alguno && dc.alguno);
            sol.ronda++;
        }
        return sol;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nElem, ronda;
    cin >> nElem >> ronda;
    if (!std::cin)
        return false;

    vector<string> v(nElem);
    for (string& x : v) cin >> x;

    int sol = resolver(v, 0, v.size(), ronda).nPartidos;

    // escribir sol
    cout << sol << endl;

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