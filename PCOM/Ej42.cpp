// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


long long int mod(int b, int p, int m) {

    if (p == 0) return 1;

    if (p % 2 == 0) {
        long long int solMedios = mod(b, p / 2, m);
        return (solMedios * solMedios) % m;
    }

    else
        return (b % m * mod(b, p - 1, m)) % m;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    long long int b, p, m;

    cin >> b;

    if (!std::cin)
        return false;

    cin >> p >> m;

    long long int calculo = mod(b, p, m);

    cout << calculo % m << endl;

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