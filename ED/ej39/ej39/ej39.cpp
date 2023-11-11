// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "bintree_eda.h"
using namespace std;


// funcioÌn que resuelve el problema
bool resolver(const bintree<int>& arbol, int min, int max) {
    if (arbol.empty())
        return true;

    if (arbol.root() < min || arbol.root() > max){
        return false;
    }
    return resolver(arbol.left(), min, arbol.root() - 1) && resolver(arbol.right(), arbol.root() + 1,max);
     
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree <int> arbol = leerArbol(-1);
    int min = INT_MIN;
    int max = INT_MAX;
    bool sol = resolver(arbol,min,max);
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

    // escribir sol


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