// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>
#include <vector>
#include<algorithm>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    // Coger como clave el nombre del alumno y como valor un conjunto con los deportes en los que este apuntado,
    // luego mostrar solo los deportes en los que el valor de conjunto.size sea 1

    string cadena;
    string deporteActual;
    cin >> cadena;
    if (!std::cin)
        return false;

    unordered_map<string, set<string>> mapaAlumnos; // Mapa con clave el alumno, y valor deportes apuntado
    unordered_map<string, int> deportes; // Mapa con clave el deporte y valor cantidad de alumnos apuntados


    while (cadena != "_FIN_") {
        if (cadena[0] >= 'A' && cadena[0] <= 'Z') {
            deportes[cadena] = 0;
            deporteActual = cadena;
        }
        else {
            mapaAlumnos[cadena].insert(deporteActual);
        }
        cin >> cadena;
    }

    for (auto it : mapaAlumnos) {
        if (it.second.size() == 1) {
            deportes[*it.second.begin()]++;
        }
    }

    vector <pair<string, int>> resumen;
    for (auto it : deportes) {
        resumen.push_back({ it.first,it.second });
    }

    sort(resumen.begin(), resumen.end(),
        [](pair<string, int> const& a, pair<string, int> const& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);  
        });
        

    for (int i = 0; i < resumen.size(); i++) {     
        cout << resumen[i].first << " " << resumen[i].second << endl;
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