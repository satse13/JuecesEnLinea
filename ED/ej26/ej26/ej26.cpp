// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70 

#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

using namespace std;
template <class T>
class list_eda_plus :public list<T> {
    using Nodo = typename list<T>::Nodo;
    using Iterador = typename list<T>::Iterador;
public:

    Iterador& advance() { // -- prefijo (recomendado)
        if (act == fan) throw std::out_of_range("fuera de la lista");
        act = act->ant;
        return *this;
    }
    Iterador& rbegin() const {
        return const_iterator(this->fantasma, this->fantasma);
    }
    Iterador& rend() const {
        return const_iterator(this->fantasma->sig, this->fantasma);
    }
};
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int aux;
    list_eda_plus<int> lista;
    cin >> aux;
    while (aux != 0) {
        lista.push_back(aux);
        cin >> aux;
    }
    auto it = lista.rbegin();
    cout << it->elem;

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
    int numCasos;
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
}