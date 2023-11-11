// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funcioÌn que resuelve el problema
bool parcOrd(const vector<int>& v,int ini,int fin) {
    if (ini + 1 == fin)
        return true;
    else {
        int m = (ini + fin) / 2;
        bool dr = parcOrd(v, m, fin);
        bool iz = parcOrd(v, ini, m);
        return dr && iz && v[ini] <= v[fin-1] && v[m] <= v[fin-1] && v[m] >= v[ini] ;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num == 0)
        return false;

    vector<int>v;
    while (num != 0) {
        v.push_back(num);
        cin >> num;   
    }

    if (parcOrd(v, 0, (int)v.size())) std::cout << "SI\n";
    else cout << "NO\n";
    
    

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