// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la

template<typename T>
void resolver(const int& k, const set<T>& conjunto) {
    auto it = conjunto.begin();
     while (it!= conjunto.end()) {
        if (it == conjunto.begin()) {
            cout << *it;
        }
        else {
            cout << " " << *it;
        }
        ++it;
    }
    cout << endl;
}

// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    cin >> tipo;
    if (!std::cin)
        return false;
    long long int k;
    cin >> k;
    if (tipo == 'N') {
        set<int> conjunto;
        int elem; 
        cin >> elem;
        while (elem != -1) {
            conjunto.insert(elem);
            if (conjunto.size() > k) {
                auto it = conjunto.begin();
                conjunto.erase(*it);
            }
            cin >> elem;
        }
        resolver(k, conjunto);
    }
    else if (tipo == 'P') {
        set<string> conjunto;
        string elem;
        cin >> elem;
        while (elem != "FIN") {
            conjunto.insert(elem);
            if (conjunto.size() > k) {
                auto it = conjunto.begin();
                conjunto.erase(*it);
            }
            cin >> elem;
        }
        resolver(k, conjunto);
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