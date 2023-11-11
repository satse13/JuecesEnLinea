// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class double_linked_list_ed_plus : public double_linked_list_ed <T> {
    using Nodo = typename double_linked_list_ed <T>::Nodo;
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
    template <typename P >
    void agrupar(P pred) {
        if (this->fantasma == this->fantasma->sig) return; // lista vacia
        // Busca la primera aparicion del elemento
        Nodo* pos = this->fantasma->sig;
        while (pos != this->fantasma && !(pred(pos->elem)))
            pos = pos->sig;
        // Pos situado en la posicion del primer elemento
        if (pos != this->fantasma) { // encontro primer elemento
        // Busca elementos posteriores para agruparlos
            Nodo* otro = pos->sig;
            while (otro != this->fantasma) {
                if (pred(otro->elem)) {
                    Nodo* mover = otro;
                    otro = otro->sig;
                    moverNodo(pos, mover);
                    pos = pos->sig;
                }
                else otro = otro->sig;
            }
        }
    }

    void interseccion(double_linked_list_ed_plus& l) {
        Nodo* aux1 = this->fantasma->sig;
        Nodo* aux2 = l.fantasma->sig;
        Nodo* ptoControl = l.fantasma->sig;
        Nodo* aux3;
        if (!(this->fantasma->sig == this->fantasma)) {
            if (l.fantasma->sig == l.fantasma) {
                while (this->fantasma->sig != this->fantasma) {
                    this->pop_back();
                }
            }
            else {
                while (aux1 != this->fantasma) {
                    if (aux1->elem == aux2->elem) {
                        aux1 = aux1->sig;
                        aux2 = ptoControl;
                    }
                    else if (aux1->elem > aux2->elem) {
                        ptoControl = aux2;
                        aux2 = aux2->sig;
                        if(aux2 == l.fantasma){
                            aux3 = aux1;
                            aux1 = aux1->sig;
                            this->borra_elem(aux3);
                            aux2 = ptoControl;
                        }
                    }
                    else {
                        aux3 = aux1;
                        aux1 = aux1->sig;
                        this->borra_elem(aux3);
                        aux2 = ptoControl;
                    }
                }
            }
        }

    }

private:
    // Se desplaza el nodo detras del apuntado por pos
    void moverNodo(Nodo* pos, Nodo* mover) {
        // desligamos el nodo a mover
        mover->sig->ant = mover->ant;
        mover->ant->sig = mover->sig;
        // enlazamos el nodo en su posicion
        mover->sig = pos->sig;
        mover->ant = pos;
        pos->sig->ant = mover;
        pos->sig = mover;
    }
};

template <typename T>
inline std::ostream& operator << (std::ostream& o, double_linked_list_ed_plus <T> const& l) {
    l.print(o);
    return o;
}
  

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    double_linked_list_ed_plus<int> lista;

    int num;
    cin >> num;

    while (num != 0) {
        lista.push_back(num);
        cin >> num;
    }
    double_linked_list_ed_plus<int> vector;

    cin >> num;

    while (num != 0) {
        vector.push_back(num);
        cin >> num;
    }

    lista.interseccion(vector);
    cout << lista; 


 
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}