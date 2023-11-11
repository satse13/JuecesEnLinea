// Ej62.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// Datos de entrada
struct tDatos {
    int numJuguetes, numNinos;
    vector<vector<int>>satis;
};
// Solucion que se va construyendo
struct tSol {
    vector <int> sol;
    int sumaSatis;
};
// Parametros :
// datos de entrada
// k - etapa
// s - Solucion que se va construyendo
// asignados - Vector de dimension el numero de juguetes marca los juguetes ya asignados
// satisMejor - la satisfacion maxima
void resolver(tDatos const& datos, int k, tSol& s, std::vector <bool >& asignados, int& satisMejor) {
    for (int i = 0; i < datos.numJuguetes; ++i) {
        s.sol[k] = i;
        if (!asignados[i]) { // es Valida
            s.sumaSatis += datos.satis[k][i];
            asignados[i] = true; // marca
            if (k == s.sol.size() - 1) { // es solucion
                if (s.sumaSatis > satisMejor) satisMejor = s.sumaSatis; // solucion mejor
            }
            else { // No es solucion
                resolver(datos, k + 1, s, asignados, satisMejor);
            }
            asignados[i] = false; // desmarca
            s.sumaSatis -= datos.satis[k][i];
        }
    }
}
bool resuelveCaso() {
    // Lectura de los datos de entrada
    tDatos datos;
    cin >> datos.numJuguetes;
    if (!cin) return false;
    cin >> datos.numNinos;
    // Lee la satisfaccion que les proporcionan los juguetes a los ninnos
    for (int i = 0; i < datos.numNinos; ++i) {
        vector <int > aux(datos.numJuguetes);
        for (int j = 0; j < datos.numJuguetes; ++j) 
            cin >> aux[j];
        datos.satis.push_back(aux);
    }
    // Obtiene una inicializacion posible para la solucion mejor
    int satisMejor = 0;
    for (int i = 0; i < datos.numNinos; ++i) {
        satisMejor += datos.satis[i][i];
    }
    // Prepara los datos de la funcion
    tSol s;
    s.sol.assign(datos.numNinos, 0);
    s.sumaSatis = 0;
    vector <bool > asignados(datos.numJuguetes, false);
    resolver(datos, 0, s, asignados, satisMejor);
    cout << satisMejor << "\n";
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