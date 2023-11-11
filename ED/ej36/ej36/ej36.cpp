// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include <math.h>
using namespace std;

struct tSol {
    bool valido = false;
    int valor;
    int prof;
};

class mult {
public:
    bool operator() (int n) {
        return n % 7 == 0;
    }
};

bool isPrime(const bintree<int> n){
    if (n.root() <= 1)  return false;
    for (int i = 2; i <= sqrt(n.root()); ++i)
        if (n.root() % i == 0)
            return false;
    return true;
}

// funcioÌn que resuelve el problema
template <typename T, typename P>
std::pair <bool, std::pair <T, int>> resolver(bintree <T> const& arbol, P propiedad) {
    bool encontrado = false;
    T nodo{}; int nivel = 0;
    if (arbol.empty() || isPrime(arbol.root())) return { false , {} };
    else if (arbol.left().empty() && arbol.right().empty())
        return { propiedad(arbol.root()) ,{ arbol.root() ,1} };
    std::queue <std::pair <int, bintree <T>>> cola;
    cola.push({ 1 , arbol });
    // en la cola solamente guardamos arboles no vacios
    while (!cola.empty() && !encontrado) {
        auto const& par = cola.front();
        auto const& a = par.second;
        if (propiedad(a.root()) && a.root() != 7) {
            encontrado = true; nodo = a.root(); nivel = par.first;
        }
        else {
            if (!a.left().empty() && !isPrime(a.left()))
                cola.push({ par.first + 1 , a.left() });
            if (!a.right().empty() && !isPrime(a.right()))
                cola.push({ par.first + 1 , a.right() });
        }
        cola.pop();
    }
    return { encontrado ,{ nodo , nivel } };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> arbol = leerArbol(-1);

    auto sol = resolver(arbol,mult());
    // escribir sol
    if (sol.first)
        std::cout << sol.second.first << ' ' << sol.second.second << '\n';
    else
        std::cout << "NO HAY \n";
    
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