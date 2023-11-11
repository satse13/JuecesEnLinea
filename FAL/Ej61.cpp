// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using tMatriz = vector<vector<int>>; 

// funcioÌn que resuelve el problema
void escribirSolucion(vector<int>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        if (i == 0) cout << sol[i];
        else cout << " " << sol[i];
    }
    cout << endl;
}

bool esValida(vector<int>& sol, vector<int>& unit, vector<string>& jug, tMatriz satis,int s,int k) {

    // Me queden unidades
    // satisfaccion valida
    // orden valido

    if (unit[sol[k]] < 0) return false;
    else if (k > 0 && k % 2 == 1) {
        int nin = k - ((k / 2) + 1); // Con esta operacion obtenemos el numero del niño que estamos tratando gracias a la k
        if (s > satis[nin][sol[k]] + satis[nin][sol[k - 1]])
            return false;
        if (!(jug[sol[k - 1]] < jug[sol[k]]))
            return false;
    } 
    return true;
}
bool resolver(vector<int>& sol, vector<int>& unit, vector<string>& jug, tMatriz satis,int s ,int k) {

    bool ret = false;
    for (int i = 0; i < jug.size(); i++) {

        sol[k] = i;
        unit[i]--;
        if (esValida(sol,unit,jug,satis,s,k)) {
            if (k == sol.size()-1) {
                escribirSolucion(sol);
                ret = true;
            }
            else {
                ret = resolver(sol, unit, jug, satis,s,k + 1) || ret;
            }
        }
        unit[i]++;
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m,n,s;
    cin >> m;
    if (!std::cin)
        return false;
    cin >> n >> s;
    vector<int> unit(m);
    vector<int> sol(2 * n);
    for (int& i : unit) cin >> i;
    vector<string>jug(m);
    for (string& s : jug) cin >> s;
    tMatriz satis(n, vector<int>(m));
    for (int i = 0; i < satis.size(); i++) {
        for (int &j : satis[i]) {
            cin >> j;
        }
    }
    if (!resolver(sol, unit, jug, satis, s,0))
        cout << "SIN SOLUCION" << endl;
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