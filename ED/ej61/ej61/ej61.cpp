// Enlace video YouTube https://youtu.be/9XR8mxv2Vfo

// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70

#include <iomanip>
#include <fstream>
#include "emergencias.h"
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {

    Urgencias<string> ur;
    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;
    string nombre;
    int gravedad;
    while (instruccion != "FIN") {
        try {
             if (instruccion == "nuevo_paciente") {
                cin >> nombre;
                cin >> gravedad;
                ur.nuevo_paciente(nombre, gravedad);
             }
             else if (instruccion == "mejora") {
                cin >> nombre;
                ur.mejora(nombre);
             }
             else if (instruccion == "siguiente") {
                string sol = ur.siguiente();
                cout << "Siguiente paciente: " << sol << endl;
             }
             else if (instruccion == "gravedad_actual") {
                cin >> nombre;
                int sol = ur.gravedad_actual(nombre);
                cout << "La gravedad de " << nombre << " es " << sol << endl;
             }
             else if (instruccion == "recuperados") {
                vector<string> recuperados = ur.recuperados();
                cout << "Lista de recuperados:";
             
                 for (string s : recuperados)
                     cout << " " << s;
                 cout << endl;
             }
        }
        catch (domain_error& de) {
            cout << "ERROR: " << de.what() << endl;
        }
        cin >> instruccion;
    }
    cout << "---" << endl;
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