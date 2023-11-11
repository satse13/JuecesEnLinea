// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus:public linked_list_ed<T>{
    using Nodo = typename linked_list_ed <T>::Nodo;
public:
    void duplicar() {

        Nodo* aux = this->prim;
        
        while (aux->sig != nullptr) {
            aux->sig = new Nodo(aux->elem, aux->sig);
            aux = aux->sig->sig;
        }
        aux->sig = new Nodo(aux->elem);
        this->ult = aux->sig; 

        
    }
    void mostrar() const {  
        Nodo* aux;
        if (this->prim != nullptr) {
            aux = this->prim;
            cout << this->prim->elem;
            aux = aux->sig;
            while (aux != nullptr) {
                cout <<" " << aux->elem;
                aux = aux->sig;
            }
        }
        cout << endl;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    cin >> num;

    if (!std::cin)
        return false;
    linked_list_ed_plus<int> lista;

    while (num != 0) {
        lista.push_back(num);
        cin >> num;
    }
    if(!lista.empty())
         lista.duplicar();
    lista.mostrar();
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