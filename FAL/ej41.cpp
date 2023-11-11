// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// funcioÌn que resuelve el problema
int resolver(vector<int> v, int ini, int fin) {
   
    if (ini >= fin)
        return v[ini];
    else if (ini + 1 == fin)
        return v[ini];
    else {
            
        int mitad = (ini + fin) / 2;

        if (v[ini] > v[mitad])
            return  resolver(v, mitad, fin);
        else
            return resolver(v, ini, mitad);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numElemementos;

    cin >> numElemementos;
    if (!std::cin)
        return false;

    vector<int> lista(numElemementos);

    for(int i = 0; i < numElemementos;i++)
        cin >> lista[i];

    int sol = resolver(lista,0,lista.size());

    cout << sol << endl;
 

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