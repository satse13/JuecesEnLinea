// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct info {
    int canicas = 0; 
    string nombre;
};

// funcioÌn que resuelve el problema
info resolver(const vector<info>& v,int ini,int fin ) {
    if (ini + 1 == fin)
        return { v[ini].canicas,v[ini].nombre };
    else if (ini + 2 == fin) {
        if (v[ini].canicas >= v[ini + 1].canicas)
            return{ v[ini].canicas + (v[ini + 1].canicas / 2),v[ini].nombre };
        else 
            return { v[ini+1].canicas + (v[ini].canicas / 2),v[ini+1].nombre };
    }
    else {

        int mitad = (ini + fin) / 2;
        info iz = resolver(v, ini, mitad);
        info der = resolver(v, mitad, fin);

        if (iz.canicas >= der.canicas) {
            return { iz.canicas + (der.canicas / 2),iz.nombre };
        }
        else
            return { der.canicas + (iz.canicas / 2),der.nombre };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n;
    if (!std::cin)
        return false;
    vector<info> v(n);
    for (info& i : v) cin >> i.nombre >> i.canicas;
    info sol = resolver(v, 0, v.size());
    cout << sol.nombre << " " << sol.canicas << endl;

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