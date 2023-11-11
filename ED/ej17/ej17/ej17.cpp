// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include<queue>
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int alumnos;
    int salto;
    cin >> alumnos;
    cin >> salto;
    if (alumnos == 0 && salto == 0)
        return false;
    queue<int> cola;
   
    for (int i = 1; i <= alumnos; i++)
        cola.push(i);
    int contador = 1;
    while (cola.size() > 1) {
        if (contador != salto+1) {
            cola.push(cola.front());
            cola.pop();
            contador++;
        }
        else {
            cola.pop();
            contador = 1;
        }
    }

    cout << cola.front() << endl;



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