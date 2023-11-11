// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema

 
// MIRAR MMAS DETENIDAMENTE COMO LO HA HECHO DANIELA

pair<bool, int> resolver(int numero, int suma) {
    if (numero < 10) {
        if (numero == 0 || suma % numero != 0)
            return { false, numero };
        else return { true, numero };
    }
    else {
        pair<bool, int> aux = resolver(numero / 10, suma + numero % 10);
        if (numero % 10 != 0 && aux.second % (numero % 10) == 0 && suma % (numero % 10) == 0)
            return { aux.first, aux.second + numero % 10 };
        return { false, aux.second + numero % 10 };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    cin >> numero;

    pair<bool, int> sol = resolver(numero, 0);
    // escribir sol
    if (sol.first)
        cout << "SI\n";
    else
        cout << "NO\n";

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