// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// funcioÌn que resuelve el problema
int resolver(const vector<int>& v, const vector <int>& v2,int ini,int fin) {

    if (ini >= fin) return v[ini];
    else if (ini + 1 == fin) return v[ini];
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] == v2[mitad]) return resolver(v, v2, mitad + 1, fin);
        else return resolver(v, v2, ini, mitad + 1);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    
    int cantidad;
    cin >> cantidad;

    vector<int> v(cantidad);
    vector<int> v2(cantidad);
    for (int i = 0; i < cantidad; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < cantidad - 1; i++) {
        cin >> v2[i];
    }

    int sol = resolver(v,v2,0,v2.size());
    
    cout << sol << endl;


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