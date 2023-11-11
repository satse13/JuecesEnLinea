// Nombre del alumno ..... Alejandro Tobias
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// IMPLEMENTACION NO FINAL

// funcioÌn que resuelve el problema
int resolver(int num) {

    if (num < 10) {
        if (num % 2 == 1)
            return (num % 10 - 1);
        else
            return (num % 10 + 1);
    }

    else {
        if (num % 2 == 1)
            return  (resolver(num / 10) * 10 + (num % 10 - 1));
        else
            return  (resolver(num / 10) * 10 + (num % 10 + 1));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    
    int num;
    cin >> num;
    cout << resolver(num) << endl;
 
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