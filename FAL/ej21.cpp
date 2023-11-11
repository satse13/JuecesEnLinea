// Nombre del alumno Alejandro Tobías Ángeles
// Usuario del Juez A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funcioÌn que resuelve el problema
vector<int> resolver(const vector<int>& v, int intervalo) {
    vector<int> sol(0);
    bool valido = false;
    int inicio;
    int contador =1;

    for (int i = 1; i < v.size(); i++) {
        if ((v[i - 1] == v[i] + 1 || v[i - 1] == v[i] - 1|| v[i-1] == v[i])) {
            contador++;
            if (!valido) {
                valido = true;
                inicio = i-1;
            }
        }
        else {
            valido = false;
            if (contador >= intervalo) {
                sol.push_back(inicio);
            }
            contador = 1;
        } 
    }
    if (contador >= intervalo)
        sol.push_back(inicio);
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numDatos, metros;
    cin >> numDatos >> metros;
    if (numDatos == 0 && metros == 0)
        return false;

    vector<int> lista(numDatos);

    for (int i = 0; i < lista.size(); i++) {
        cin >> lista[i];
    }

    vector<int> sol = resolver(lista,metros);

    cout << sol.size() << " ";
    if (sol.size() != 0) {
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
        }
    }
    cout << endl; 

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