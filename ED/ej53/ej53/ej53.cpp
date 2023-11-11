// IMPORTANTE
// Nombre del alumno: Alejandro Tobias Angeles
// Usuario del juez: A70

// Las torres del desierto

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <unordered_map>
#include <map>
using namespace std;

enum Direccion { Norte, Sur, Este, Oeste };

class Desierto {
public :
    unordered_map<string, pair<int, int>> mapaTorres;// mapa con el nombre de la torre y sus coordenadas 
    unordered_map<int, map<int, string>> mapaCoordenadasX; // mapa con clave la x y valor mapa con las y
    unordered_map<int, map<int, string>> mapaCoordenadasY; // lo mismo al reves

    void anyadir_torre(const string& nombre, int x, int y) { // Coste logaritmico en funcion de la cantidad de torres 
        if (mapaTorres.count(nombre)) {                      // que haya en el mapa ordenado
            throw domain_error("Torre ya existente");
        }
        if (mapaCoordenadasX.count(x) && mapaCoordenadasX[x].count(y)) {
            throw domain_error("Posicion ocupada");
        }
        mapaTorres[nombre].first = x;
        mapaTorres[nombre].second = y;
        mapaCoordenadasX[x].insert({ y,nombre });
        mapaCoordenadasY[y].insert({ x,nombre });
    }

    void eliminar_torre(const string& nombre) { // Coste logaritmico en funcion de la cantidad de torres
                                                 // que haya en el mapa ordenado
        if (!mapaTorres.count(nombre)) {
            throw domain_error("Torre no existente");
        }
 
        mapaCoordenadasX[mapaTorres[nombre].first].erase(mapaTorres[nombre].second);
        mapaCoordenadasY[mapaTorres[nombre].second].erase(mapaTorres[nombre].first);
        mapaTorres.erase(nombre);
    }

    pair<int,int> posicion(const string& nombre) const { // Coste constante porque es un acceso a un unordered_map
        if (!mapaTorres.count(nombre)) {
            throw domain_error("Torre no existente");
        }
        return { mapaTorres.at(nombre).first, mapaTorres.at(nombre).second };
    }

    pair<bool, string> torre_en_posicion(int x, int y) const { // Logaritmico por acceso a mapa ordenado
        if (mapaCoordenadasX.count(x) && mapaCoordenadasX.at(x).count(y)) {
            return { true,mapaCoordenadasX.at(x).at(y) };
        }
        else
            return { false,""};
    }

    string torre_mas_cercana(const string& nombre, const Direccion& dir) const{ //Logaritmico en funcion de las torres del mapa ordenado
        if (mapaTorres.count(nombre) == 0) 
            throw domain_error("Torre no existente");
       
        pair<int, int> coordenadas = mapaTorres.at(nombre);
        if (dir == Norte) {
            auto it = mapaCoordenadasX.at(coordenadas.first).find(coordenadas.second);
            if (it != mapaCoordenadasX.at(coordenadas.first).end()) {
                ++it;
            }
            if (it != mapaCoordenadasX.at(coordenadas.first).end())
                return{ it->second };
            else
                throw domain_error("No hay torres en esa direccion");
        }
        else if (dir == Sur) {
            auto it = mapaCoordenadasX.at(coordenadas.first).find(coordenadas.second);
            if (it != mapaCoordenadasX.at(coordenadas.first).begin()) {
                --it;
                return{ it->second };
            }
            else
                throw domain_error("No hay torres en esa direccion");
        }
        else if (dir == Este) {
            auto it = mapaCoordenadasY.at(coordenadas.second).find(coordenadas.first);
            if (it != mapaCoordenadasY.at(coordenadas.second).end()) {
                ++it;
            }
            if (it != mapaCoordenadasY.at(coordenadas.second).end())
                return{ it->second };
            else
                throw domain_error("No hay torres en esa direccion");
        }
        else {
            auto it = mapaCoordenadasY.at(coordenadas.second).find(coordenadas.first);
            if (it != mapaCoordenadasY.at(coordenadas.second).begin()) {
                --it;
                return{ it->second };
            }
            else
                throw domain_error("No hay torres en esa direccion");
        }
        
    }



private:
};

// Transforma un string en el tipo enumerado Direccion
// Para la llamada a la función torre_mas_cercana
Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    Desierto d;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "anyadir_torre") {
                std::string nombre; int x, y;
                std::cin >> nombre >> x >> y;
                d.anyadir_torre(nombre, x, y);
            }
            else if (op == "eliminar_torre") {
                std::string nombre;
                std::cin >> nombre;
                d.eliminar_torre(nombre);
            }
            else if (op == "posicion") {
                std::string nombre;
                std::cin >> nombre;
                std::pair<int, int> sol = d.posicion(nombre);
                std::cout << sol.first << ' ' << sol.second << '\n';
            }
            else if (op == "torre_en_posicion") {
                int x, y; std::cin >> x >> y;
                std::pair<bool, std::string> sol = d.torre_en_posicion(x, y);
                if (sol.first)
                    std::cout << "SI " << sol.second << '\n';
                else std::cout << "NO\n";
            }
            else {
                std::string nombre; std::string dir;
                std::cin >> nombre >> dir;
                std::string sol = d.torre_mas_cercana(nombre, calculaDir(dir));
                std::cout << sol << '\n';
            }
        }
        catch (std::domain_error const& e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;

}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());//Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


