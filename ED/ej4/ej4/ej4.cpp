// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70


#include <iomanip>
#include <fstream>
#include <vector>
#include "Pelicula.h"
#include <string>
#include <algorithm>
using namespace std;


// funcioÌn que resuelve el problema
void resolver(vector<Pelicula>& v) {
    sort(v.begin(), v.end());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numPeliculas;
    cin >> numPeliculas;

    if (numPeliculas == 0)
        return false;

    vector<Pelicula>v(numPeliculas);
    Hora ini, duracion;
    string nombre;
    Pelicula p;
  
        for (int i = 0; i < numPeliculas; i++) {
            try {
                cin >> ini;
                cin >> duracion;
                getline(cin, nombre);
                p = Pelicula(ini, duracion, nombre);
                v[i] = p;
            }
            catch (invalid_argument& ia) {
                cout << ia.what() << endl;
            }
        }
    
     
    resolver(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].getFin() << " " << v[i].getNombre() << endl;
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