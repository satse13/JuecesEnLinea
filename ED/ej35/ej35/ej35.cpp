// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
using namespace std;


// funcioÌn que resuelve el problema
bool resolver(bintree<char> iz,bintree<char> der) {

    if (iz.empty() && der.empty()) 
        return true;
    if (iz.empty() || der.empty())
        return false;

    return  (iz.root() == der.root() && resolver(iz.left(), der.right()) && resolver(iz.right(), der.left()));


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<char> arbol1 = leerArbol('.');
    bintree<char> iz = arbol1.left();
    bintree<char> der = arbol1.right();
  
    
    bool sol = resolver(iz,der);
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