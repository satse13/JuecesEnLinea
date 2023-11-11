// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// funcioÌn que resuelve el problema
vector<int> resolver(const vector<int>& datos) {

    vector<int> sol(3);

    sol[0] = 0;
    sol[2] = datos.size();
    int rachaActual = 0;
     

    for (int i = 0; i < datos.size();i++) {
        if (datos[i] > 0) {
            rachaActual++;
            if (rachaActual > sol[0]) {
                sol[0] = rachaActual;
                sol[1] = 1;
                sol[2] = datos.size() - i - 1;
            }
            else if (rachaActual == sol[0]) {
                sol[1]++;
                sol[2] = datos.size() - i - 1;

            }
        }
        else
            rachaActual = 0;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numPartidos;
    cin >> numPartidos;

    if (!std::cin)
        return false;

    vector<int> lista(numPartidos);

    for (int i = 0; i < numPartidos; i++) {
        cin >> lista[i];
    }

    vector<int> sol(3); // sol[0] = mejor racha, sol[1] = veces, sol[2] = tiempo

    sol = resolver(lista);

    cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;

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