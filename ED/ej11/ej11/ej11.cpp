// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
#include "linked_list_ed_plus.h"
using namespace std;

/*template <typename T>
class linked_list_ed_plus : public linked_list_ed <T> {
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

    void unir(linked_list_ed_plus& l) {
        Nodo* aux1,aux2,aux3;

        aux1 = this->prim;
        aux2 = l.prim;
        if (this->prim->elem > l.prim->elem) {
            this->prim = l.prim;
            aux2 = l.prim->sig;
            this->prim->sig = aux1;
        }
        aux3 = this->prim;
 /*       while (aux2 != nullptr) {
            if (aux1->elem > aux2->elem) {
                aux3->sig = aux2;
                //            aux4 = aux2->sig;
                //            aux2->sig = aux1;
                //            aux2 = aux4;
                aux2 = aux2->sig;
                while (aux2 != nullptr && aux1->elem > aux2->elem) {
                    aux3 = aux2;
                    aux2 = aux2->sig;
                }
                aux3->sig = aux1;
                aux3 = aux1;
                aux1 = aux1->sig;
            }
            else {
                aux3 = aux1;
                aux1 = aux1->sig;
            }
            while (this->ult->sig != nullptr && this->ult->elem <= this->ult->sig->elem)
                this->ult = this->ult->sig;
        }
       }
       };*/
    

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
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