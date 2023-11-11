// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funcioÌn que resuelve el problema
struct par {
    int sol = 0;
    bool si = false;
};

par resolver(vector<int>&v ,const int n,int ini,int fin) {
    
    par sol;
    
    if (ini >= fin) {
        return sol;
    }
    else if (ini + 1 == fin && ini + n == v[ini]) {
        sol.sol = v[ini];
        sol.si = true;
        return sol;
    }   
    else if (ini + 1 == fin && ini + n != v[ini]) {
        return sol;
    }
    else {

        int mitad = (ini + fin - 1) / 2;
        if (mitad + n <= v[mitad]) {
            return (resolver(v, n, ini, mitad + 1));
        }
        else
            return resolver(v, n, mitad + 1, fin);
    }
 }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int num, tachar;
    cin >> num >> tachar;
    vector<int> v(num);
    for (int i = 0; i < num; i++) {
        cin >> v[i];
    }

    par sol = resolver(v,tachar,0,v.size());
    // escribir sol

    if (sol.si)
        cout << sol.sol << endl;
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