// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// funcioÌn que resuelve el problema
int resolver(const bintree<char>& a, int& diametro) {
    if (a.empty()) {
        return 0;
    }
    else {
        int iz = resolver(a.left(), diametro);
        int der = resolver(a.right(), diametro);
        diametro = max(diametro,iz+der+1);
       
        return max(iz, der) + 1;
    }
}
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree <char> arbol = leerArbol('.');
    int diam = 0;
    int sol = resolver(arbol,diam);
    cout << diam << endl;
 
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