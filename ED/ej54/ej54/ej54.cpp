// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70

#define puntos first
#define iterador second

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <fstream>
using namespace std;

class DGT{
private:
    unordered_map<string, pair<int, list<string>::iterator>> mapaConductores;
    list<string> listas[16];
     
public:

    void nuevo(const string& dni) {
        if (mapaConductores.count(dni))
            throw domain_error("Conductor duplicado");
        mapaConductores[dni].puntos = 15;
        listas[15].push_front(dni);
        mapaConductores[dni].iterador = listas[15].begin();
    }
   /* void quitar(const string& dni, const int& puntos) {
        if (!mapaConductores.count(dni))
            throw domain_error("Conductor inexistente");
        int prevPunt = mapaConductores[dni].puntos;
        if (puntos > mapaConductores[dni].puntos) {
            mapaConductores[dni].puntos = 0;
        }
        else 
            mapaConductores[dni].puntos -= puntos;
        if (prevPunt != mapaConductores[dni].puntos) {
            listas[prevPunt].erase(mapaConductores[dni].iterador);
            listas[mapaConductores[dni].puntos].push_front(dni);
            mapaConductores[dni].iterador = listas[mapaConductores[dni].puntos].begin();
        }
    }*/
    // Prueba para ver si ahora da correcto
    void quitar(const string& dni, const int& puntos) {
        if (mapaConductores.count(dni) == 0) throw domain_error("Conductor inexistente");
        int antP = mapaConductores[dni].puntos;
        if (antP != 0) {
            antP - puntos >= 0 ? mapaConductores[dni].puntos -= puntos : mapaConductores[dni].puntos= 0;
            int nuevP = mapaConductores[dni].puntos;

            //lo cambio en la lista
            listas[antP].erase(mapaConductores.at(dni).iterador);
            listas[nuevP].push_front(dni);
            mapaConductores[dni].iterador = listas[nuevP].begin();
        }
    }
    /*void recuperar(const string& dni, const int& puntos) {
        if (!mapaConductores.count(dni))
            throw domain_error("Conductor inexistente");
        int prevPunt = mapaConductores[dni].puntos;
        if (puntos + mapaConductores[dni].puntos > 15) {
            mapaConductores[dni].puntos = 15;
        }
        else
            mapaConductores[dni].puntos += puntos;
        if (prevPunt != mapaConductores[dni].puntos) {
            listas[prevPunt].erase(mapaConductores[dni].iterador);
            listas[mapaConductores[dni].puntos].push_front(dni);
            mapaConductores[dni].iterador = listas[mapaConductores[dni].puntos].begin();
        }
    }*/

    void recuperar(const string& dni, const int& puntos) {
        if (mapaConductores.count(dni) == 0) throw domain_error("Conductor inexistente");
        int antP = mapaConductores[dni].puntos;
        if (antP != 15) {
            antP + puntos <= 15 ? mapaConductores[dni].puntos += puntos : mapaConductores[dni].puntos = 15;
            int nuevP = mapaConductores[dni].puntos;

            //lo cambio en la lista
            listas[antP].erase(mapaConductores.at(dni).iterador);
            listas[nuevP].push_front(dni);
            mapaConductores[dni].iterador = listas[nuevP].begin();
        }
    }

    int consultar(const string& dni) const{
        if (!mapaConductores.count(dni))
            throw domain_error("Conductor inexistente");
        return mapaConductores.at(dni).puntos;
    }

    int cuantos_con_puntos(const int& puntos) const {
        if (puntos < 0 || puntos > 15)
            throw domain_error("Puntos no validos");
         
        return (int)listas[puntos].size();
    }

    list<string> lista_por_puntos(const int& puntos) const {
        if (puntos < 0 || puntos > 15)
            throw domain_error("Puntos no validos");
        return listas[puntos];
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

    DGT sis = DGT();
    while (instruccion != "FIN") {
        try {
            if (instruccion == "nuevo") {
                string dni; cin >> dni;
                sis.nuevo(dni);
            }
            else if (instruccion == "cuantos_con_puntos") {
                int puntos; cin >> puntos;
                int sol = sis.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << sol << endl;
            }
            else if (instruccion == "lista_por_puntos") {
                int puntos; cin >> puntos;
                list<string> sol = sis.lista_por_puntos(puntos);
                cout << "Tienen " << puntos << " puntos:";
                for (const string& s : sol)
                    cout << " " << s;
                cout << endl;
            }
            else if (instruccion == "quitar") {
                string dni; cin >> dni;
                int puntos; cin >> puntos;
                sis.quitar(dni, puntos);
            }
            else if (instruccion == "consultar") {
                string dni; cin >> dni;
                int sol = sis.consultar(dni);
                cout << "Puntos de " << dni << ": " << sol << endl;
            }
            else if (instruccion == "recuperar") {
                string dni; cin >> dni;
                int puntos; cin >> puntos;
                sis.recuperar(dni, puntos);
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