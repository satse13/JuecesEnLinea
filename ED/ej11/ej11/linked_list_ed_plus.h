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

    void unir(linked_list_ed_plus& l) {
        Nodo* aux1, aux2, aux3;

        aux1 = this->prim;
        aux2 = l.prim;
        if (this->prim->elem > l.prim->elem) {
            this->prim = l.prim;
            aux2 = l.prim->sig;
            this->prim->sig = aux1;
        }
        aux3 = this->prim;
              while (aux2 != nullptr) {
                   if (aux1->elem > aux2->elem) {
                       aux3->sig = aux2;
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
};