// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include"Personas.h"
#include <string>
using namespace std;

// funcioÌn que resuelve el problema
template <class T, class Predicate>
void remove_if(list<T>& lista, Predicate pred) {
    auto it1 = lista.begin();
    while (it1 != lista.end()) {
        if (!pred(*it1))
            it1 = lista.erase(it1);
        else
            it1++;
    }
    
}
void mostrar(const list<Persona>& lista) {
    auto it = lista.begin();
    if (it != lista.end()) {
        std::cout << *it << endl;
        ++it;
    }
    for (; it != lista.end(); ++it)
        std::cout << *it << endl;
    


}

class edadValida {

private:
    int min, max;
   

public:
    edadValida(int d, int u) :min(d), max(u) {}
    bool operator()(Persona p) {
        return p.getEdad() >= min && p.getEdad() <= max;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int pasajeros, min, max;
    cin >> pasajeros >> min >> max;

    if (pasajeros == 0 && min == 0 && max == 0)
        return false;

    list<Persona> lista;

    for (int i = 0; i < pasajeros; i++) {
        int edad;
        string nombre;
        char aux;
        cin >> edad;
        cin.get();
        getline(cin, nombre);
        Persona p(edad,nombre);
        lista.push_back(p);
    }

    remove_if(lista, edadValida(min, max));
    mostrar(lista);
    cout << "---" << endl;

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