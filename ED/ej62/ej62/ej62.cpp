// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "empleo.h"

 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;

    Empleo emp;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "altaOficina") {
                string nombre;
                cin >> nombre;
                string empleo;
                cin >> empleo;
                emp.altaOficina(nombre, empleo);
            }
            else if (instruccion == "ofertaEmpleo") {
                string empleo;
                cin >> empleo;
                string sol = emp.ofertaEmpleo(empleo);
                cout << empleo << ": " << sol << endl;
            }
            else if (instruccion == "listadoEmpleos") {
                string nombre;
                cin >> nombre;
                vector<string> sol = emp.listadoEmpleos(nombre);
                cout << nombre << ":";
                for (string s : sol) {
                    cout << " " << s;
                }
                cout << endl;
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