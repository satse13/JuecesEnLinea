// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Carnet.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    Carnet sistema;

    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;
    while (instruccion != "FIN") {
        try {
            if (instruccion == "nuevo") {
                string segundo;
                cin >> segundo;
                sistema.nuevo(segundo);
            }
            else if (instruccion == "cuantos_con_puntos") {
                int segundo;
                cin >> segundo;
                int valor = sistema.cuantos_con_puntos(segundo);
                cout << "Con " << segundo << " puntos hay " << valor << endl;
            }
            else if (instruccion == "quitar") {
                string segundo;
                int puntos;
                cin >> segundo;
                cin >> puntos;
                sistema.quitar(segundo, puntos);
            }
            else if (instruccion == "consultar") {
                string segundo;
                cin >> segundo;
                int valor = sistema.consultar(segundo);
                cout << "Puntos de " << segundo << ": " << valor << endl;
            }
        }
        catch (domain_error& de) {
            cout << "ERROR: " << de.what() << endl;
        }
        cin >> instruccion;
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