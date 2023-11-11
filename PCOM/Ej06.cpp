// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 40;
long long int dp[MAX];

// funcioÌn que resuelve el problema
long long int resolver(const int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 5;
    else {
        if (dp[n] == -1) {
            dp[n] = resolver(n - 1) + 4 * resolver(n - 2) + 2 * resolver(n - 3);
        }
        return dp[n];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
    long long int sol = resolver(n);
    cout << sol << endl;


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}