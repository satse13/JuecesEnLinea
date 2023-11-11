// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "autoescuela.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    Autoescuela<string,string> autoes;
    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;

    while (instruccion != "FIN") {
         try {
            if (instruccion == "alta") {
                string alumno;
                string profesor;
                cin >> alumno;
                cin >> profesor;
                autoes.alta(alumno, profesor);
            }
            else if (instruccion == "es_alumno") {
                string alumno;
                string profesor;
                cin >> alumno;
                cin >> profesor;
                if (autoes.es_alumno(alumno, profesor))
                    cout << alumno << " es alumno de " << profesor << endl;
                else
                    cout << alumno << " no es alumno de " << profesor << endl;
            }
            else if (instruccion == "examen") {
                string profesor;
                cin >> profesor;
                int puntos;
                cin >> puntos;
                cout << "Alumnos de " << profesor << " a examen:" << endl;
                set<string> sol = autoes.examen(profesor, puntos);
                auto it = sol.begin();
                while (it != sol.end()) {
                    cout << *it << endl;
                    ++it;
                }
            }
            else if (instruccion == "actualizar") {
                string alumno;
                int puntos;
                cin >> alumno;
                cin >> puntos;
                autoes.actualizar(alumno, puntos);
            }
            else if (instruccion == "puntuacion") {
                string alumno;
                cin >> alumno;
                int sol = autoes.puntuacion(alumno);
                cout << "Puntuacion de " << alumno << ": " << sol << endl;
            }
            else if (instruccion == "aprobar") {
                string alumno;
                cin >> alumno;
                autoes.aprobar(alumno);
            }

        }
        catch(domain_error& de){
            cout << "ERROR" << endl;
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