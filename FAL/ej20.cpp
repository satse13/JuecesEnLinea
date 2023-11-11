// Nombre del alumno: Alejandro Tobías Ángeles
// Usuario del Juez: A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
using namespace std;

struct solucion {
    int tamanio;
    int posicionInicial = 0;
    int posicionFinal = 0;
};

// funcioÌn que resuelve el problema
solucion resolver(const vector<int>& v,int intervalo) {

    solucion sol;
    int sumaActual = 0;
    
    for (int i = 0; i < intervalo; i++) {
        sumaActual  += v[i];
    }
    
    sol.posicionInicial = 0;
    sol.tamanio = sumaActual;

    for (int i = intervalo; i < v.size(); i++) {
        sumaActual -= v[i - intervalo];
        sumaActual += v[i];

        if (sumaActual > sol.tamanio) {
            sol.tamanio = sumaActual;
            sol.posicionInicial = i - intervalo + 1;
            sol.posicionFinal = i - intervalo + 1;
        }
        else if (sumaActual == sol.tamanio) {
            sol.posicionFinal = i - intervalo + 1;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numKilometros, intervalo;
    cin >> numKilometros >> intervalo;

    if (numKilometros == 0 && intervalo == 0)
        return false;

    vector<int> lista(numKilometros);

    for(int i = 0; i < lista.size();i++){
        cin >> lista[i];
    }

    solucion sol = resolver(lista,intervalo);

    cout << sol.tamanio << " " << sol.posicionInicial << " " << sol.posicionFinal << endl;

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