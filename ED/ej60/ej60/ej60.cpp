// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "clase.h"
 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;

    Clase clase;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "nuevo_estudiante") {
                string dni;
                int grupo;
                cin >> dni;
                cin >> grupo;
                clase.nuevo_estudiante(dni, grupo);
            }
            else if (instruccion == "grupo_estudiante") {
                string dni;
                cin >> dni;
                int sol = clase.grupo_estudiante(dni);
                cout << dni << " esta en el grupo " << sol << endl;
            }
            else if (instruccion == "promocionar") {
                string dni;
                cin >> dni;
                clase.promocionar(dni);
            }
            else if (instruccion == "novato") {
                int grupo;
                cin >> grupo;
                string sol = clase.novato(grupo);
                cout << "Novato de " << grupo << ": " << sol << endl;
            }
            else if (instruccion == "graduados") {
                vector<string> sol = clase.graduados();
                cout << "Lista de graduados: ";
                if (sol.size() > 0)
                    cout << sol[0];
                int i = 1;
                while (i < sol.size()) {
                    cout << " " << sol[i];
                    i++;
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