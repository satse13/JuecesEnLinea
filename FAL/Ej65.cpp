// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using tMatriz = vector<vector<int>>;

// funcioÌn que resuelve el problema

struct tDatos {
    vector<int> sol;
    int sumaT = 0;
};

void resolver(tDatos& sol, vector<bool>& marcas, tMatriz& matriz,vector<int>& acum ,int& solMejor, int k) {

    for (int i = 0; i < marcas.size(); i++) {
        sol.sol[k] = i;
        if (!marcas[i]) {
            marcas[i] = true;
            sol.sumaT += matriz[k][i];
            if (k == sol.sol.size() - 1) {
                if (sol.sumaT < solMejor) {
                    solMejor = sol.sumaT;
                }
            }
            else {
                if (sol.sumaT + acum[k + 1] < solMejor) {
                    resolver(sol, marcas, matriz, acum, solMejor, k + 1);
                }
            }
            marcas[i] = false;
            sol.sumaT -= matriz[k][i];
        }


    }

   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    tMatriz matriz(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int& j : matriz[i]) cin >> j;
    }
    tDatos sol;
    sol.sol.assign(n, 0);
    vector<bool> marcas(n);
    marcas.assign(n, false);

    vector<int> acum;

    int aux = 0;
    for (int i = 0; i < n; i++) {
        aux = matriz[i][0];
        for (int j = 1; j < n; j++) {
            if (matriz[i][j] < aux) 
                aux = matriz[i][j];
        }
        acum.push_back(aux);
    }

    for (int i = acum.size() - 1; i > 0; i--) {
        acum[i - 1] += acum[i];
    }

    int solMejor = 0;
    for (int i = 0; i < n; i++) {
        solMejor += matriz[i][i];
    }
    resolver(sol, marcas, matriz,acum ,solMejor, 0);
    cout << solMejor << endl;
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