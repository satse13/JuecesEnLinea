// Nombre del alumno ..... Alejandro TobÃ­as Ãngeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÃŒÂn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int gente;
    cin >> gente;
    if (gente == 0)
        return false;

    map <string, int> mapa;
    string nombre;
    string nota;
    int puntos;
    cin.get();
    for (int i = 0; i < gente; i++) {

        getline(cin, nombre);
        getline(cin, nota);

        if (nota == "CORRECTO") puntos = 1;
        else puntos = -1;

        if (!mapa.count(nombre)) {
            mapa.insert({ nombre, puntos });
        }
        else {
            mapa.at(nombre) += puntos;
        }

    }

    for (auto i : mapa) {
        if (i.second != 0)
            cout << i.first << ", " << i.second << endl;
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