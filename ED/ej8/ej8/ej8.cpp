// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
#include "Horas.h"
 
using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed <T > {
    using Nodo = typename linked_list_ed <T>::Nodo;

public: 
    void eliminarPares() {
        int contador = 1;
        Nodo* aux = this->prim;
        Nodo* aux2;
        if (aux->sig != nullptr) {
            while (aux->sig != nullptr && aux->sig->sig != nullptr) {
                aux2 = aux->sig->sig;
                delete(aux->sig);
                aux->sig = aux2;
                aux = aux->sig;
            }
        }
        if (aux->sig != nullptr) {
            delete(aux->sig);
            aux->sig = nullptr;
        }
        this->ult = aux;
        
    }
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

};
// funcioÌn que resuelve el problema
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num; 
    cin >> num;
    if (num == 0)
        return false;

    linked_list_ed_plus<Hora> lista;
    Hora hora;
    for (int i = 0; i < num; i++) {
        cin >> hora;
        lista.push_back(hora);
    }
 
    // escribir sol
    lista.eliminarPares();
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