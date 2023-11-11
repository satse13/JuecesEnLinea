// Nombre del alumno:Alejandro Tobías Ángeles
// Usuario del Juez:A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct solucion{
    int longitud = 0;
    int suma = 0;
    int fecha = 0;
};

// funcioÌn que resuelve el problema
solucion resolver(const vector<int>& v) {
    solucion sol;

    int sumaActual = 0;
    int longActual = 0;
     
    for (int i = 0; i < v.size(); i++) {
        sumaActual += v[i];
        if (sumaActual > sol.suma || (sumaActual == sol.suma && longActual + 1 < sol.longitud)) {
            sol.suma = sumaActual;
            longActual++;
            sol.fecha = i - longActual + 1;
            sol.longitud = longActual;
            
        }
        else if (sumaActual <= 0) {
            sumaActual = 0;
            longActual = 0;
        }
        else {
            longActual++;
        }  
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numElem;
    cin >> numElem;

    if (!std::cin)
        return false;

    vector<int> v(numElem);

    for (int i = 0; i < numElem; i++) {
        cin >> v[i];
    }

    solucion sol = resolver(v);

    cout << sol.suma << " " << sol.fecha << " " << sol.longitud << endl;

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