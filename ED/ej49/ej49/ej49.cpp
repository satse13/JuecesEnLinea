// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numPeliculas;
    cin >> numPeliculas;

    if (numPeliculas == 0)
        return false;

    unordered_map <string, pair<int, vector<pair<string, int>>>> mapaP; // Es un mapa con clave pelicula y valor veces que aparece en total dicha pelicula y un vector que guarda el nombre y tiempo de aparicion de cada actor
    unordered_map<string, int> mapaA; // Mapa con clave actor y tiempo total que aparece en pantalla 
    

    for (int i = 0; i < numPeliculas; i++) { // Por cada pelicula 
        string pelicula;
        int actores;
        cin >> pelicula;
        cin >> actores;

        auto& p = mapaP[pelicula];
        for (int j = 0; j < actores; j++) {
            string actor;
            int tiempo;

            cin >> actor;
            cin >> tiempo;
            p.second.push_back({ actor,tiempo }); // Metemos en el mapa de peliculas cuanto tiempo en cada pelicula sale el actor
        }
    }
    
    int veces;
    string maxP; // Pelicula que mas veces aparece
    int emisiones = 0;
    set<string> sActores; // Conjunto con los actores que mas tiempo salen
    int  tiempo = 0;
    cin >> veces;
    for (int j = 0; j < veces; j++) { // Por cada pelicula emitida
        string p;
        cin >> p;

        auto it = mapaP.find(p); // Esto es un par con la clave y el valor
        
        it->second.first++; // Le sumamos uno a las emisiones de la pelicula p

        for (auto a : it->second.second) { // Por cada par dentro del vector de pares de 
            mapaA[a.first] += a.second;
            if (it->second.first >= emisiones) {
                emisiones = it->second.first;
                maxP = it->first;
            }

            if (mapaA[a.first] > tiempo) {
                tiempo = mapaA[a.first];
                sActores.clear();
                sActores.insert(a.first);
            }

            else if(mapaA[a.first] == tiempo){
                sActores.insert(a.first);
            }
        }
    }

    cout << emisiones << " " << maxP << endl;

    auto it = sActores.begin();

    cout << tiempo << " ";

    while (it != sActores.end()) {
        if (it == sActores.begin())
            cout << *it;
        else
            cout << " " << *it;
        ++it;
    }
    cout << endl;

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