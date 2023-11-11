#pragma once
using namespace std;
template <typename T>
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
};