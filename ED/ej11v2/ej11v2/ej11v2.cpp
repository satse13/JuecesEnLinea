// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed <T>::Nodo;
public:
    void mostrar() const {
        Nodo* aux;
        if (this->prim != nullptr) {
            aux = this->prim;
            cout << this->prim->elem;
            aux = aux->sig;
            while (aux != nullptr) {
                cout << " " << aux->elem;
                aux = aux->sig;
            }
        }
        cout << endl;
    }

    void unir(linked_list_ed_plus& lista) {
        //Si la lista dada esta vacia
        if (this->prim == nullptr) {
            this->prim = lista.prim;
            this->ult = lista.ult;
            lista.prim = nullptr;
            lista.ult = nullptr;
        }
        //Si hay elementos que copiar
        else if (lista.prim != nullptr) {
            //Caso especial si el primer elemento de la lista a copiar es menor 
           //que el primer elemento de lista dada (no tenemos anterior)
            if (this->prim->elem > lista.prim->elem) {
                Nodo* aux = this->prim;
                this->prim = lista.prim;
                lista.prim = lista.prim->sig;
                this->prim->sig = aux;
            }
            Nodo* aux2 = this->prim;
            Nodo* aux3 = this->prim->sig;
            while (lista.prim != nullptr) {
                if (aux3 == nullptr) {
                    aux2->sig = lista.prim;
                    lista.prim = lista.prim->sig;
                    aux2->sig->sig = nullptr;
                }
                else if (aux3->elem >= lista.prim->elem) {
                    aux2->sig = lista.prim;
                    lista.prim = lista.prim->sig;
                    aux2->sig->sig = aux3;
                }
                else
                    aux3 = aux3->sig;
                aux2 = aux2->sig;
            }
            lista.ult = nullptr;
        }
    }
};

void resuelveCaso() {
    // leer los datos de la entrada

   linked_list_ed_plus<int> v, l;

    int num;
    cin >> num;

    while (num != 0) {
        v.push_back(num);
        cin >> num;
    }

    cin >> num;
    while (num != 0) {
        l.push_back(num);
        cin >> num;
    }

    v.unir(l);
    v.mostrar();



    // escribir sol

    
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