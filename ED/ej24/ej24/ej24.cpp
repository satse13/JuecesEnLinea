// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Horas.h"
 using namespace std;

// funcioÌn que resuelve el problema
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num == 0)
        return false;
    
    list<Hora> lista;
    for (int i = 0; i < num; i++) {
        Hora h;
        cin >> h;
        lista.push_back(h);
    }
     
    auto it = lista.begin();
    bool par = false;
    while (it != lista.end()){
        if (!par) {
            it++;
        }
        else
            it = lista.erase(it);
        par = !par;
    }
    auto it2 = lista.begin();
    if (it2 != lista.end()) {
         cout << *it2;
        ++it2;
    }
    for (; it2 != lista.end(); ++it2)
        cout << ' ' << *it2;
     cout << '\n';

     
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