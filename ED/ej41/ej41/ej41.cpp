// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "set.h"
#include "treemap.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int jugadores;
    cin >> jugadores;
    if (!std::cin)
        return false;

    int cartas;
    cin >> cartas;

    map<string, set<int>> mapa;

    for (int i = 1; i <= jugadores; i++) {
        string jugador = "J";
        jugador += to_string(i);
        set<int> conjunto;
        int elemento;
        cin >> elemento;
        conjunto.insert(elemento);
        mapa.insert({jugador,conjunto});
    }
    int j = jugadores;
    int i = 1;
    while (j < cartas) {
        string jugador = "J";
        jugador += to_string(i);
        int elemento;
        cin >> elemento;
        bool correcto =  mapa[jugador].insert(elemento);
        if (!correcto) {
            mapa[jugador].erase(elemento);
        }
        i++;
        if (i == jugadores+1) i = 1;
        j++;
    }
    
    for (int i = 1; i <= jugadores; i++) {
        string jugador = "J" + to_string(i);
        cout << jugador + ": {";
        auto it = mapa[jugador].begin();
        for (int j = 0; j < mapa[jugador].size(); j++) {
            if (j == 0) { 
                cout << *it;
            }
            else {
                cout << ", " << *it;
            }
            ++it;
        }
        cout << "}" << endl;
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