// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// funcioÌn que resuelve el problema
int resolver(vector<int>& lista) {
    
    int sol;

    int contador = 1, contMax = 0;
    sol = lista[0];

    for (int i = 1; i < lista.size(); i++) {
        if (lista[i] == lista[i - 1]) {
            contador++;
            if (contador > contMax) {
                contMax = contador;
                sol = lista[i];
            }
        }
        else {
            contador = 1;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int accidentes;
    cin >> accidentes;

    if (accidentes==-1)
        return false;

    vector<int> lista(accidentes);

    for (int i = 0; i < accidentes; i++) 
        cin >> lista[i];
    
    sort(lista.begin(), lista.end());

    int sol = resolver(lista);

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