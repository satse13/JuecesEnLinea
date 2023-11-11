// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complejo.h"
 
 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Complejo<float> c;
    cin >> c;

    int n;
    cin >> n;
    Complejo<float> zn_prev, zn;
    zn_prev = Complejo<float>(0);
    bool converge = true;
    int i = 0;
    while (i < n && converge) {
        zn = zn_prev * zn_prev + c;
        if (zn.mod() > 2) 
            converge = false;
        zn_prev = zn;
        i++;
    }
    converge ? cout << "SI\n" : cout << "NO\n";
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