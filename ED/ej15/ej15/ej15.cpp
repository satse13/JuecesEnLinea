// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack_eda.h"
#include <string>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int par = 0;
    int cor = 0;
    int llav = 0;

    string p;
    getline(cin, p);
    
    if (!std::cin)
        return false;
    stack<char> pila;
    bool sol = true;
    int i = 0;
    while(i < p.size() && sol) {
        if (p[i] == ')') {
            par++;
            if (pila.empty() || pila.top() != '(')
                sol = false;
            else if (pila.top() == '(')
                pila.pop();
        }
        else if (p[i] == '}') {
            llav++;
            if (pila.empty() || pila.top() != '{')
                sol = false;
            else if (pila.top() == '{')
                 pila.pop();
        }
        else if (p[i] == ']') {
            cor++;
            if (pila.empty() || pila.top() != '[')
                sol = false;
            else if(pila.top() == '[')
                pila.pop();
        }
        else if (p[i] == '(') {
            pila.push(p[i]);
            par++;
        }
        else if (p[i] == '[') {
            pila.push(p[i]);
            cor++;
        }
        else if (p[i] == '{') {
            pila.push(p[i]);
            llav++;
        }
        i++;
    }
    if (sol && par%2 == 0 && cor %2 == 0 && llav%2 == 0 && pila.empty())
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
     

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