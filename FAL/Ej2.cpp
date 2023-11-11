// Nombre del alumno - Alejandro Tobías Ángeles
// Usuario del Juez - A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema
bool resolver(const vector<int>& lista, int posicion) {

    bool resultado = true;
    int maximo, minimo;


    maximo = lista[0];

    for (int i = 1; i <= posicion; i++) {

        if (lista[i] > maximo)
            maximo = lista[i];
    }

    int j = posicion + 1;

    while (j < lista.size()) {

        if (lista[j] <= maximo)
            resultado = false;

        j++;
    }


    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int numElementos, posicion;


    cin >> numElementos;
    cin >> posicion;

    vector<int> lista(numElementos);

    for (int i = 0; i < numElementos; i++)
        cin >> lista[i];

    if (resolver(lista, posicion))
        cout << "SI" << endl;
    else
        cout << "NO" << endl;


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