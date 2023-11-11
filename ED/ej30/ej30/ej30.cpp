// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70

using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

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

    
private:
    int numNodos(Link r) {
        if (r == nullptr) {
            return 0;
        }
        else {
            return numNodos(r->left) + numNodos(r->right)+1;
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
    int calcAltura(Link r){
        if (r == nullptr)
            return 0;
        else
            return(1 + max(calcAltura(r->left), calcAltura(r->right)));
            
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


// funcioÌn que resuelve el problema
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree_ext<char>arbol = leerArbol_ext('.');
    cout << arbol.nodos() << " " << arbol.hojas() << " " << arbol.altura() << endl;

 

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