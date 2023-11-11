// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "double_linked_list_ed.h"
using namespace std;

template <typename T >
class double_linked_list_ed_plus : public double_linked_list_ed <T> {
    using Nodo = typename double_linked_list_ed <T >::Nodo;
public:
    void print(std::ostream& o) const {
        Nodo* aux = this->fantasma->sig;
        if (aux != this->fantasma) {
            o << aux->elem;
            aux = aux->sig;
        }
        while (aux != this->fantasma) {
            o << ' ' << aux->elem;
            aux = aux->sig;
        }
        o << '\n';
    }
    
    void intercambiar() {
        Nodo* aux = this->fantasma->sig;
        swapAdy(aux, aux->sig);
        aux = aux->sig;
        while (this->fantasma != aux && aux->sig != this->fantasma ) {
            swapAdy(aux, aux->sig);
            aux = aux->sig;
        }
    }   

private: 
    void swapAdy(Nodo*& prev, Nodo*& post) {
        Nodo* aux = post;
        Nodo* aux2 = prev;
        prev->ant->sig = post;
        prev->sig = post->sig;
        Nodo* aux3 = prev->ant;
        prev->ant = aux;
        aux->sig = prev;
        aux->ant = aux3;
        prev->sig->ant = prev;
    }
};

template <typename T>
inline std::ostream& operator <<(std::ostream& o, double_linked_list_ed_plus <T > const& l) {
    l.print(o);
    return o;
}

 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    cin >> num;

    if (num == 0)
        return false;

    double_linked_list_ed_plus<int> lista;
    int a;
    for (int i = 0; i < num; i++) {
        cin >> a;
        lista.push_back(a);
    }

    lista.intercambiar();
    cout << lista;

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