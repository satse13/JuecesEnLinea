// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

class iPud {
    using Iterador = typename std::list<string>::iterator;

private:

 
    struct infoCancion {
        string artista;
        int duracion;
        pair<bool, Iterador> lista;
        pair<bool, Iterador> reproducidas;
    };

    unordered_map<string, infoCancion> mapaCanciones;
    list<string> playList;
    list<string> reproducidas;
    int duracionTotal;
public:
    iPud(){}

    void addSong(const string& s, const string& a, const int& d) {
        if (mapaCanciones.count(s))
            throw domain_error("addSong");
        mapaCanciones.insert({ s,{a,d} });
    }

    void addToPlaylist(const string& s) {
        if (!mapaCanciones.count(s))
            throw domain_error("addToPlaylist");
        if (!mapaCanciones[s].lista.first) {
            playList.push_back(s);
            mapaCanciones[s].lista = { true,--playList.end() };
            duracionTotal += mapaCanciones[s].duracion;
        }
    }

    string current() const {
        if (playList.empty())
            throw domain_error("current");
        return playList.front();
    }

    string play() {
        if (playList.empty())
            throw length_error("No hay canciones en la lista");
        string c = playList.front();
        playList.pop_front();
        mapaCanciones[c].lista = { false,Iterador() };
        if (mapaCanciones[c].reproducidas.first) {
            reproducidas.erase(mapaCanciones[c].reproducidas.second);
        }
        reproducidas.push_front(c);
        mapaCanciones[c].reproducidas = { true,reproducidas.begin() };
        duracionTotal -= mapaCanciones[c].duracion;
        return c;
    }

    int totalTime() const {
        return duracionTotal;
    }
  
    list<string> recent(const int& N) {
        if (reproducidas.empty())
            throw length_error("No hay canciones recientes");
        list<string> sol;
        auto it = reproducidas.begin();
        for (int i = 0; i < N && it != reproducidas.end(); i++, ++it)
            sol.push_back(*it);
        return sol;
    }

    void deleteSong(const string& s) {
        if (!mapaCanciones.count(s))
            return;
        if (mapaCanciones[s].reproducidas.first)
            reproducidas.erase(mapaCanciones[s].reproducidas.second);
        if (mapaCanciones[s].lista.first) {
            playList.erase(mapaCanciones[s].lista.second);
            duracionTotal -= mapaCanciones[s].duracion;
        }
        mapaCanciones.erase(s);
    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;
    iPud sis;
    while (instruccion != "FIN") {
        try {
            if (instruccion == "addSong") {
                string nombre; cin >> nombre;
                string artista; cin >> artista;
                int duracion; cin >> duracion;
                sis.addSong(nombre, artista, duracion);
            }
            else if (instruccion == "addToPlaylist") {
                string nombre; cin >> nombre;
                sis.addToPlaylist(nombre);
            }
            else if (instruccion == "play") {
                    string sol = sis.play();
                    cout << "Sonando " << sol << endl;
            }
            else if (instruccion == "current") {
                string sol = sis.current();
             }
            else if (instruccion == "totalTime") {
                int sol = sis.totalTime();
                cout << "Tiempo total " << sol << endl;
            }
            else if (instruccion == "deleteSong") {
                string nombre; cin >> nombre;
                sis.deleteSong(nombre);
            }
            else if (instruccion == "recent") {
                int num; cin >> num;
                list<string> sol = sis.recent(num);
                cout << "Las " << sol.size() << " mas recientes" << endl;
                for (string& s : sol)
                    cout << "    " << s << endl;
            }
            else 
                throw std::domain_error("Instruccion invalida");
        }
        catch (domain_error& de) {
            cout << "ERROR " << de.what() << endl;
        }
        catch (length_error& le) {
            cout << le.what() << endl;
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