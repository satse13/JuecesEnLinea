// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
using namespace std;
template<typename T>
class linked_list_ed_plus:public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
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
    void eliminarRepetidos() {
        Nodo* aux = this->prim;
        Nodo* aux2;

        while (aux != nullptr && aux->sig != nullptr) {
            if (aux->sig->elem == aux->elem) {
                aux2 = aux->sig;
                aux->sig = aux2->sig;
                if (aux2 == this->ult)
                    this->ult = aux;
                delete aux2;
            }
            else {
                aux = aux->sig;
            }
        }
    }

    void invertir() {
        Nodo* p = nullptr;
        Nodo* q = this->prim;
        Nodo* aux;
        while (q != nullptr) {
            aux = q->sig;
            q->sig = p;
            p = q;
            q = aux;
        }
        this->ult = this->prim;
        this->prim = p;
 
    }
};
// funcioÌn que resuelve el problema
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numero;
    cin >> numero;

    if (!std::cin)
        return false;
    linked_list_ed_plus<int> lista ;

    while (numero != 0) {
        lista.push_back(numero);
        cin >> numero;
    }

    lista.invertir();
    lista.mostrar();
 
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