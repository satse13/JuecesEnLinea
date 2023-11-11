// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
 
//template <class T >
int busquedaIzq(vector <int> const& v, int elem, int ini, int fin) {
    if (ini >= fin) return ini; // vector vacio
    else if (ini + 1 == fin) return ini; // vector 1 elemento
    else { // Vector de dos o mas elementos
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] < elem) return busquedaIzq(v, elem, mitad + 1, fin);
        else return busquedaIzq(v, elem, ini, mitad + 1); // incluye la mitad
    }
}
// Funcion que busca la posicion mas a la derecha del elemento
//template <class T >
int busquedaDer(vector <int> const& v, int elem, int ini, int fin) {
    if (ini >= fin) return ini; // vector vacio
    else if (ini + 1 == fin) return ini; // vector un elemento
    else { // vector 2 o mas elementos
        int mitad = (ini + fin) / 2;
        if (elem < v[mitad]) return busquedaDer(v, elem, ini, mitad);
        else return busquedaDer(v, elem, mitad, fin); // Incluye el elemento mitad
    }
}
bool resuelveCaso() {
    int numelem, elem;
    cin >> numelem;
    if (!std::cin) return false;
    cin >> elem;
    vector <int > lista(numelem);
    for (int& n : lista) cin >> n;
    // Busca en el lado izquierdo
    int posIz = busquedaIzq(lista, elem, 0, (int)lista.size());
    if (posIz == lista.size() || lista[posIz] != elem)
        cout << "NO EXISTE \n";
    else {
        // Si existe el elemento busca en el lado derecho
        int posDr = busquedaDer(lista, elem, 0, (int)lista.size());
        if (posIz == posDr) cout << posIz << "\n";
        else cout << posIz << " " << posDr << "\n";
    }
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