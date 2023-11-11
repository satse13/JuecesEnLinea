// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema
 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (!std::cin)
        return false;
    vector<int>v(num);
    stack<int> pila;
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    int longitud =0;
    int p = (int)v.size();
    for (int i = v.size()-1;i >= 0; i--) {
        while (!pila.empty() && v[i] >= v[pila.top()]) {
            pila.pop();
        }
        if (pila.empty() && longitud < v.size() - i) {
            longitud = (int)v.size() - i; 
            p = i;
        }
        else if (!pila.empty() && longitud < pila.top() - i) {
            longitud = pila.top() - i; p = i;
        }
        pila.push(i);
    }
    cout << longitud << " " << p << endl;

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