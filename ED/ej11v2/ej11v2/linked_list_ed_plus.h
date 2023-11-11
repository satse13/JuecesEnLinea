#pragma once
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
        
         if (this->prim == nullptr) {
            this->prim = lista.prim;
            lista.prim = nullptr;
            lista.ult = nullptr;
        }
         else if (lista.prim != nullptr) {
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