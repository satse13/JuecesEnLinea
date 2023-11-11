// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// funcioÌn que resuelve el problema
int resolver(const vector<int>& lista, int cantidad) {

    int solucion = 0,max,actual = 0;

    for (int i = 0; i < cantidad; i++) {
        actual += lista[i];
    }

    max = actual;

    for (int i = cantidad; i < lista.size(); i++) {

        actual = actual - lista[i - cantidad]; // No sumas siempre cada intervalo, restas el anterior y sumas el nuevo 
        actual += lista[i];                    // asi te ahorras hacer sumas que ya has hecho antes

        if (actual >= max) {
            max = actual;
            solucion = i - cantidad + 1;
        }

    }

    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numPaginas, cantidad;

    cin >> numPaginas >> cantidad;

    if (numPaginas == 0 && cantidad == 0)
        return false;
    
    vector<int> lista(numPaginas);

    for (int i = 0; i < numPaginas; i++) {

        cin >> lista[i];
    }

    int sol;

    sol = resolver(lista,cantidad);

    cout << sol << endl;

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