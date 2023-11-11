// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "bintree_eda.h"
using namespace std;

// funcioÌn que resuelve el problema
vector<int> resolver(vector<int> p,vector<int> i) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    string preorders;
    getline(cin, preorders);
    vector<int> preorder;
    if (!std::cin)
        return false;

    string inorders;
    getline(cin, inorders);
    vector<int> inorder;
    for (int i = 0; i < preorders.size(); i++) {
        preorder[i] = preorders[i];
    }
    for (int i = 0; i < inorders.size(); i++) {
        inorder[i] = inorders[i];
    }
    // escribir sol
    vector<int> sol = resolver(inorder, preorder);

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