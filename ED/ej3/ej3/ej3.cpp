// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Hora.h"
using namespace std;

const Hora fallo;

// funcioÌn que resuelve el problema
Hora resolver(Hora& cons, vector<Hora>& v, int ini, int fin) {
 
    if (ini + 1 == fin)
        return v[ini];
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < cons)
            return resolver(cons, v, mitad + 1, fin);
        else
            return resolver(cons, v, ini, mitad + 1);
    }
}


// si la consulta es mayor que la mitad mira a la dcha 
// si no, me devuelve ese 
// 
// 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numHoras, consultas;

    cin >> numHoras >> consultas;

    if (numHoras == 0 && consultas == 0)
        return false;

    vector<Hora> v(numHoras);
    Hora consulta;
 
    for (int i = 0; i < numHoras; i++) {
        cin >> v[i];
    }

    Hora sol;

    for (int i = 0; i < consultas; i++) {
        
        try {
            cin >> consulta;
            sol = resolver(consulta, v, 0, v.size());
            if (sol < consulta)
                cout << "NO";
            else
                cout << sol;
            cout << endl;

        }
        catch (invalid_argument& ia) {
            cout << ia.what() << endl;
        }
    }
    
    
    // escribir sol

    cout << "---" << endl;

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