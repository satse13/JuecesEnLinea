// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;

template <class T >
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {
    auto it1 = ini1; auto it2 = ini2;
    while (it1 != fin1 && it2 != fin2) {
        if (*it1 == *ini2) {  
            auto aux1 = it1; it2 = ini2;
            while (aux1 != fin1 && it2 != fin2 && *aux1 == *it2) {
                ++aux1;
                ++it2;
            }
            if (it2 != fin2) ++it1;
        }
        else ++it1;
    }
    return it1;
}   


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n1, n2;
    cin >> n1 >> n2;
    if (n1 == 0 && n2 == 0)
        return false;

    list<int> lista1;
    list<int> lista2;
    int aux;
    for (int i = 0; i < n1; i++) {
        cin >> aux;
        lista1.push_back(aux);
    }
    for (int i = 0; i < n2; i++) {
        cin >> aux;
        lista2.push_back(aux);
    }
    auto iterador1 = lista1.begin();
    while (iterador1 != lista1.end()) {
        iterador1 = Mysearch(iterador1, lista1.end(), lista2.begin(), lista2.end());
        if (iterador1 != lista1.end()) {
            for (int i = 0; i < lista2.size(); ++i) {
                iterador1 = lista1.erase(iterador1);
            }
        }
    }
    auto it = lista1.begin();
    if (it != lista1.end()) {
        cout << *it;
        ++it;
    }
    for (; it != lista1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';



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