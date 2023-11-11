// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include<sstream>
#include "linked_list_ed.h"
using namespace std;

template <typename T>
class linked_list_ed_plus :public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:
    // Aquí se recorre la lista para ver qué elementos cumplen una determinada propiedad
    template <typename Predicate>
    void mostrarPropiedad(Predicate pred, ostream& o = cout) const {
        Nodo* aux = this->prim;
        while (aux != nullptr && !pred(aux->elem))
            aux = aux->sig;
        if (aux != nullptr) {
            o << aux->elem;
            aux = aux->sig;
            while (aux != nullptr) {
                if (pred(aux->elem))
                    o << ' ' << aux ->elem;
                aux = aux->sig;
            }
        }
        o << "\n";
    }
};

class letra {
public: 
    letra(char ltr) :carac(ltr) {}
    bool operator()(string palabra) {
        return palabra[0] == carac;
    }
private: 
    char carac;
};

// funcioÌn que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    char c;
    std::cin >> c;
    if (!std::cin) return false;
    linked_list_ed_plus <std::string> lista;
    std::string str;
    getline(std::cin, str); // para saltar el final de linea
    getline(std::cin, str); // lee la linea del caso
    std::stringstream ss(str); // construye el objeto ss de tipo stringstream
    while (ss) {
        std::string aux;
        ss >> aux;
        lista.push_back(aux);
    }
 
    lista.mostrarPropiedad(letra(c));

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