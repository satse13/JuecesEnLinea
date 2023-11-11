// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>
 
using namespace std;

struct tAccidente {
    string fecha;
    int fall;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    cin >> numCasos;
    if (!std::cin)
        return false;
    stack<tAccidente> pila;
    tAccidente acc;
    
    for (int i = 0; i < numCasos; i++) {
        cin >> acc.fecha;
        cin >> acc.fall;
       
        while (!pila.empty() && pila.top().fall <= acc.fall) {
            pila.pop();
        }
        if (!pila.empty()) {
            cout << pila.top().fecha << endl;
        }
        else
            cout << "NO HAY" << endl;
      
        pila.push(acc);
    }
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