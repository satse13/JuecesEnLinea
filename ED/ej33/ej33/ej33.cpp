// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct tSol {
    int equipo = 0;
    bool valido = false;
    int mayor = 0;
};
// funcioÌn que resuelve el problema
tSol resolver(const bintree<int>& a) {

    if (a.empty()) {
        return { 0,false,0 };
    }
    else {
        tSol iz = resolver(a.left());
        tSol der = resolver(a.right());

        if (iz.valido || der.valido) {
            return { iz.equipo + der.equipo ,true,a.root() + max(iz.mayor,der.mayor) };
        }
        else if (a.root() != 0) {
            return { 1,true,a.root() };
        }
        else
            return{ 0,false,0 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol;
    arbol = leerArbol(-1);
    tSol sol = resolver(arbol);
    // escribir sol
    cout << sol.equipo << " " << sol.mayor << endl;

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