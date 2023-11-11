// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_eda.h"
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    cin >> numElem;
    if (numElem == 0)
        return false;
    set<int> conjunto;
    for (int i = 0; i < numElem; i++) {
        int elem;
        cin >> elem;
        conjunto.insert(elem);
    }
    int numPreguntas;
    cin >> numPreguntas;
    for (int i = 0; i < numPreguntas; i++) {
        int elem;
        cin >> elem;
        pair<bool, int> sol;
        sol = conjunto.lower_bound(elem);
        if (sol.first)
            cout << sol.second << endl;
        else
            cout << "NO HAY" << endl;
    }

    cout << "---" << endl;
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