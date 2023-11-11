// Nombre del alumno - Alejandro Tobías Ángeles
// Usuario del Juez - A64


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// funcioÌn que resuelve el problema
int resolver(int& max) {

    int elemento, veces;

    cin >> elemento;
    max = elemento;
    veces = 1;


    cin >> elemento;

    while (elemento != 0) {

        if (elemento > max) {

            max = elemento;
            veces = 1;
        }

        else if (elemento == max)
            veces++;

        cin >> elemento;
    }

    return veces;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int max;
    int sol = resolver(max);

    cout << max << " " << sol << endl;

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