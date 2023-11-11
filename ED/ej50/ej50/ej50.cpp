// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    struct info_problema {
        bool resuelto = false; 
        int fallos = 0;
    };

    struct info_equipo{
        int resueltos = 0;
        int tiempo;
        unordered_map<string, info_problema> problemas;
    };

    struct info_result {
        string nombre;
        int numRes;
        int tiempo;
        bool operator<(info_result const& r) const {
           return (numRes > r.numRes)|| (numRes == r.numRes && tiempo < r.tiempo) || (numRes == r.numRes && tiempo == r.tiempo && nombre < r.nombre);
        }
    };

    string equipo;
    string problema;
    string veredicto;
    int minuto;

    unordered_map<string, info_equipo> equipos;

    while (cin >> equipo && equipo != "FIN") {
        cin >> problema >> minuto >> veredicto;
        if (!equipos[equipo].problemas[problema].resuelto) { // Si el equipo no habia resuelto el problema
            if (veredicto == "AC") {
                equipos[equipo].problemas[problema].resuelto = true; // Se pone el problema resuelto para ese equipo
                equipos[equipo].resueltos++; // Se suma uno a los ejercicios resueltos
                equipos[equipo].tiempo += minuto + equipos[equipo].problemas[problema].fallos * 20; // Se suma el tiempo total
            }
            else
                equipos[equipo].problemas[problema].fallos++;
        } // Si esta resuelto se ignora
    }

    vector<info_result> result;

    for (auto it : equipos) {
        result.push_back({ it.first,it.second.resueltos,it.second.tiempo });
    }

    sort(result.begin(), result.end());

    for (auto const& r : result) {
        cout << r.nombre << " " << r.numRes << " " << r.tiempo << endl;
    }
    cout << "---" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}