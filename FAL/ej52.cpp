// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// funcioÌn que resuelve el problema
int resolver(vector <int> v,int ini,int fin) {
    if (ini == fin)
        return v[ini];
    else if (ini + 1 == fin)
        return v[ini];
    else{
    
        int mitad = (ini + fin) / 2;
        
        if (mitad == v[mitad] - v[0])
            return resolver(v, mitad,fin);
        else
            return resolver(v, ini,mitad);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int elem;
    cin >> elem;

    vector<int> v(elem);
    for (int i = 0; i < elem; i++) {
        cin >> v[i];
    }

    int sol = resolver(v,0,v.size());
    // escribir sol
    cout << sol + 1<< endl;


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