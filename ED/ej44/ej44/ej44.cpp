// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int lineas;
    cin >> lineas;
    if (lineas == 0)
        return false;

    map<string, vector<int>> mapa;
    cin.get();
    string linea;
    for (int i = 1; i <= lineas; ++i) {
        getline(cin, linea);
        stringstream ss(linea);
        string palabra;
        while (ss >> palabra) {
            if (palabra.size() > 2) {
                for (char& c : palabra) c = tolower(c);
                if (!mapa.count(palabra)) mapa[palabra] = { i };
                else if (mapa[palabra][mapa[palabra].size() - 1] < i) mapa[palabra].push_back(i);
            }
        }
    }

    for (auto a : mapa) {
        cout << a.first << ' ';
        for (int i = 0; i < a.second.size(); ++i) {
            cout << a.second[i];
            if (i < a.second.size() - 1) cout << ' ';
        }
        cout << '\n';
    }
    cout << "---\n";
    
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