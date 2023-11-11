// IMPORTANTE
// Nombre del alumno: Alejandro Tobias Angeles
// Usuario del juez: A70


// Elecciones presidenciales

#include <iostream>
#include <string>
#include <vector> 
#include <fstream>
#include <stdexcept>
#include <unordered_map>
#include <map>


using namespace std;

class ConteoVotos {
private:
    struct infoEstado {
        int numCompromisarios;
        string mayoritario;
        int votos_max;

    };

    unordered_map<string,infoEstado> mapaEstados;
    map <string, pair<int,unordered_map<string, int>>> mapaPartidos; // String nombre partidos, luego para cada estado lso votos
 
public:
    void nuevo_estado(const string& nombre, int num_compromisarios) { // O(1) todas las operaciones son constantes
        if (mapaEstados.count(nombre)) 
            throw domain_error("Estado ya existente");
        mapaEstados.insert({ nombre,{ num_compromisarios,"",0 } });
    }
    void sumar_votos(const string& estado, const string& partido, int num_votos) { // O(log n) en el numero de partidos. Todas
        if(!mapaEstados.count(estado))                                             //  las operaciones en las que se accede a un valor
            throw domain_error("Estado no encontrado");                             // de mapaPartidos son logaritmicas
        mapaPartidos[partido].second[estado] += num_votos;
        if (mapaEstados[estado].mayoritario == "") {
            mapaEstados[estado].mayoritario = partido;
            mapaEstados[estado].votos_max = mapaPartidos[partido].second[estado];
            mapaPartidos[partido].first += mapaEstados[estado].numCompromisarios;
        }
        else if (mapaEstados[estado].votos_max < mapaPartidos[partido].second[estado]) {
            mapaPartidos[mapaEstados[estado].mayoritario].first -= mapaEstados[estado].numCompromisarios;
            mapaEstados[estado].mayoritario = partido;
            mapaEstados[estado].votos_max = mapaPartidos[partido].second[estado];
            mapaPartidos[partido].first += mapaEstados[estado].numCompromisarios;
        }
    }
    string ganador_en(const string& estado) const { // O(1) todas las operaciones son constantes
        if (!mapaEstados.count(estado))
            throw domain_error("Estado no encontrado");
        return mapaEstados.at(estado).mayoritario;
    }

    vector<pair<string, int>> resultados() const  { // O(n) lineal en el numero de partidos 
        vector<pair<string, int>> sol;

        for (auto& it : mapaPartidos) {
            if (it.second.first > 0) {
                sol.push_back({ it.first,it.second.first });
            }
        }
        return sol;
    }


};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    ConteoVotos cv;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "nuevo_estado") {
                std::string nombre; int num_compromisarios;
                std::cin >> nombre >> num_compromisarios;
                cv.nuevo_estado(nombre, num_compromisarios);
            }
            else if (op == "sumar_votos") {
                std::string estado, partido;
                int num_votos;
                std::cin >> estado >> partido >> num_votos;
                cv.sumar_votos(estado, partido, num_votos);
            }
            else if (op == "ganador_en") {
                std::string estado;
                std::cin >> estado;
                std::string sol = cv.ganador_en(estado);
                std::cout << "Ganador en " << estado << ": " << sol << '\n';
            }
            else if (op == "resultados") {
                std::vector<std::pair<std::string, int>> sol = cv.resultados();
                for (std::pair<std::string, int> const& s : sol)
                    std::cout << s.first << ' ' << s.second << '\n';
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
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());//Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


