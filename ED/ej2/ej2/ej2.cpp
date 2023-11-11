// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Hora.h"


// funcioÌn que resuelve el problema
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int ho1, ho2, m1, m2, s1, s2;
    char aux;
    Hora h1;
    cin >> ho1 >> aux >> m1 >> aux >> s1;
    cin >> ho2 >> aux >> m2 >> aux >> s2;

    try {
        Hora h1(ho1, m1, s1);
        Hora h2(ho2,m2,s2);
        
        cout << h1 + h2 << endl;
    }
    catch (overflow_error& oe) {
        cout << oe.what() << endl;
    }
    catch (invalid_argument& ia) {
        cout << ia.what() << endl;
    }
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