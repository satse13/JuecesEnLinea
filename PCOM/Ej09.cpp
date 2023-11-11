// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct gasolinera {
    int x;
    int r;
};
class ord {
public:
    bool operator()(const gasolinera a, const gasolinera b){
        return a.x-a.r < b.x-b.r;
    }
};
// funcioÌn que resuelve el problema
int resolver(const vector<gasolinera>& v,const int& largo) {
    int i = 0;
    while (!end) {

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int largo, gas;
    cin >> largo >> gas;
    if (largo == 0 && gas == 0)
        return false;
    vector<gasolinera>v(gas);
    for (gasolinera g : v) {
        cin >> g.x >> g.r;
    }
    sort(v.begin(), v.end(), ord());
    int sol = resolver(v,largo);
    cout << sol << endl;
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