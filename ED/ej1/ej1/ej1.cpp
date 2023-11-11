// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iomanip>
#include <fstream>
#include "Hora.h"

// funcioÌn que resuelve el problema
void escribir(Hora& h1, Hora& h2) {
    if (h1 < h2)
        cout << h1 << " " << h2;
    else if (h2 == h1)
        cout << "IGUALES";
    else
        cout << h2 << " " << h1;
    cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    Hora h1(0, 0, 0), h2(0, 0, 0);
    cin >> h1 >> h2;
    escribir(h1, h2);
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}