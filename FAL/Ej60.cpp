// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void escribirSol(vector<int>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        if (i == 0)
            cout << sol[i];
        else
            cout << " " << sol[i];
    }
    cout << endl;
}

bool esValida(vector<int>& sol,vector<string>& jug, int k) {

    if (k > 0 && k % 2 == 1) {  // Se comprueba que el segundo juguete es mayor alfabeticamente que el primero
        return jug[sol[k]] > jug[sol[k - 1]];
    }

    return true;
}
// funcioÌn que resuelve el problema
bool resolver(vector<int>& sol, vector<string>& jug,int k) {
    bool ret = false;
    for (int i = 0; i < jug.size(); i++) {
        sol[k] = i;
        if (k == 1 && sol[0] == 1 && sol[1] == 2) {
            int z = 0;
        }
        if (esValida(sol, jug, k)) {
            if (k == sol.size() - 1) {
                escribirSol(sol);
                ret = true;
            }
            else
                ret = (resolver(sol, jug, k + 1) || ret);
        }
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m;
    cin >> m;
    if (!std::cin)
        return false;
    int n;
    cin >> n;
    vector<int> sol(2 * n);
    vector<string> jug(m);
    for (string& s : jug) cin >> s;
    
    if (!resolver(sol, jug, 0)) {
        cout << "SIN SOLUCION" << endl;
    }
    cout << endl;

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