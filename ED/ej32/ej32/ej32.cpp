// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct tSol {
    int acum = 0; 
    int correcto;
};

tSol sumaNodos(bintree <int> const& arbol) { // O(N)
    if (arbol.empty()) {
        return { 0,0 };
    }
    else {
        tSol res_iz = sumaNodos(arbol.left());
        tSol res_dr = sumaNodos(arbol.right());
        if(arbol.root() == res_iz.acum + res_dr.acum)
            return { res_iz.acum + res_dr.acum + arbol.root(),res_iz.correcto + res_dr.correcto +1};
        else
        return { res_iz.acum + res_dr.acum + arbol.root(), res_iz.correcto + res_dr.correcto };
    }
}


 


 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree <int> arbol = leerArbol(-1);
    tSol sol;
    sol = sumaNodos(arbol);
    cout << sol.correcto << endl;
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