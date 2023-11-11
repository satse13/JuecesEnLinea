// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;


template <class T >
class bintree_ext : public bintree <T> {
    using Link = typename bintree <T>::Link;
public:
    bintree_ext() : bintree <T >() {}
    bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T> const& r) :
        bintree <T>(l, e, r) {}
    bool equilibrado()
    {
        return equilibrado(this->raiz).eq;
    }
    int nodos() {
        return this->numNodos(this->raiz);
    }
    int hojas() {
        return this->numHojas(this->raiz);
    }
    int altura() {
        return this->calcAltura(this->raiz);
    }
    T menor() {
        return minimo(this->raiz);
    }

private:
    int numNodos(Link r) {
        if (r == nullptr) {
            return 0;
        }
        else {
            return numNodos(r->left) + numNodos(r->right) + 1;
        }
    }
    int numHojas(Link r) {
        int cont = 0;
        if (r != nullptr) {
            if (r->left == nullptr && r->right == nullptr) {
                cont = 1;
            }
            else {
                if (r->left != nullptr) {
                    cont += numHojas(r->left);
                }
                if (r->right != nullptr) {
                    cont += numHojas(r->right);
                }
            }
        }
        return cont;
    }
    int calcAltura(Link r) {
        if (r == nullptr)
            return 0;
        else
            return(1 + max(calcAltura(r->left), calcAltura(r->right)));
    }
    T minimo(Link r) {
        auto minim = r->elem;
        if(r->left != nullptr){
            minim = min(minim, minimo(r->left));
        }
        if (r->right != nullptr) {
            minim =  min(minim, minimo(r->right));      
        }
        return minim;
    }
};

template <typename T>
inline bintree_ext <T> leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_ext <T> iz = leerArbol_ext(vacio);
        bintree_ext <T> dr = leerArbol_ext(vacio);
        return { iz , raiz , dr };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char in;
    cin >> in;
    if (!std::cin)
        return false;
    if (in == 'N') {
        auto arbol = leerArbol_ext(-1);
        int menor = arbol.menor();
        cout << menor << endl;

    }
    else {
       string nulo = "#";
       auto arbol = leerArbol_ext(nulo);
       string menor = arbol.menor();
       cout << menor << endl;  
    }
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